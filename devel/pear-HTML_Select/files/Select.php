<?php
/* vim: set expandtab tabstop=4 shiftwidth=4: */
// +----------------------------------------------------------------------+
// | PHP Version 4                                                        |
// +----------------------------------------------------------------------+
// | Copyright (c) 1997, 1998, 1999, 2000, 2001 The PHP Group             |
// +----------------------------------------------------------------------+
// | This source file is subject to version 2.0 of the PHP license,       |
// | that is bundled with this package in the file LICENSE, and is        |
// | available at through the world-wide-web at                           |
// | http://www.php.net/license/2_02.txt.                                 |
// | If you did not receive a copy of the PHP license and are unable to   |
// | obtain it through the world-wide-web, please send a note to          |
// | license@php.net so we can mail you a copy immediately.               |
// +----------------------------------------------------------------------+
// | Author: Adam Daniel <adaniel1@eesus.jnj.com>                         |
// +----------------------------------------------------------------------+
//
// $Id: Select.php,v 1.10.2.2 2002/04/09 19:04:19 ssb Exp $

require_once 'PEAR.php';
require_once 'HTML/Common.php';

/**
 * Class to dynamically create an HTML SELECT
 *
 * @author       Adam Daniel <adaniel1@eesus.jnj.com>
 * @version      1.2
 * @since        PHP4.04pl1
 * @access       public
 */
class HTML_Select extends HTML_Common
{
    
    /**
     * Contains the select options
     *
     * @var       array
     * @since     1.0
     * @access    private
     */
    var $_options = array();
    
    /**
     * Default values of the SELECT
     * 
     * @var       string
     * @since     1.0
     * @access    private
     */
    var $_values = array();

    /**
     * Class constructor
     *
     * @param     string    $name       (optional)Name attribute of the SELECT
     * @param     int       $size       (optional) Size attribute of the SELECT
     * @param     bool      $multiple   (optional)Whether the select will allow multiple 
     *                                  selections or not
     * @param     mixed     $attributes (optional)Either a typical HTML attribute string 
     *                                  or an associative array
     * @param     int       $tabOffset  (optional)Number of tabs to offset HTML source
     * @since     1.0
     * @access    public
     * @return    void
     * @throws    
     */
    function HTML_Select($name = '', $size = 1, $multiple = false, $attributes = null, $tabOffset = 0)
    {
        HTML_Common::HTML_Common($attributes, $tabOffset);
        $attr = array('name' => $name, 'size' => $size);
        if ($multiple) {
            $attr[] = 'multiple="multiple"';
        }
        $this->updateAttributes($attr);
        $this->setSelectedValues(array());
    }
    
    /**
     * Returns the current API version 
     * 
     * @since     1.0
     * @access    public
     * @return    double
     * @throws    
     */
    function apiVersion()
    {
        return 1.2;
    }

    /**
     * Sets the default values of the select box
     * 
     * @param     mixed    $values  Array or comma delimited string of selected values
     * @since     1.0
     * @access    public
     * @return    void
     * @throws    
     */
    function setSelectedValues($values)
    {
        if (is_string($values)) {
            $values = split("[ ]?,[ ]?", $values);
        }
        $this->_values = $values;  
    }
    
    /**
     * Returns an array of the selected values
     * 
     * @since     1.0
     * @access    public
     * @return    array of selected values
     * @throws    
     */
    function getSelectedValues()
    {
        return $this->_values;
    }

    /**
     * Adds a new OPTION to the SELECT
     *
     * @param     string    $text       Display text for the OPTION
     * @param     string    $value      Value for the OPTION
     * @param     bool      $selected   Whether the option is selected or not
     * @param     mixed     $attributes Either a typical HTML attribute string 
     *                                  or an associative array
     * @since     1.0
     * @access    public
     * @return    void
     * @throws    
     */
    function addOption($text, $value, $selected = false, $attributes = null)
    {
        if ($selected && !in_array($value, $this->_values)) {
            $this->_values[] = $value;
        }
        
        $attributes = $this->_parseAttributes($attributes);
        $attr['value'] = $value;
        $this->_updateAttrArray($attributes, $attr);
        $this->_options[] = array('text' => $text, 'attr' => $attributes);
    }
    
    /**
     * Loads the options from an associative array
     * 
     * @param     array    $arr     Associative array of options
     * @param     mixed    $values  (optional) Array or comma delimited string of selected values
     * @since     1.0
     * @access    public
     * @return    PEAR_Error on error or true
     * @throws    PEAR_Error
     */
    function loadArray($arr, $values=null)
    {
        if (!is_array($arr)) {
            return new PEAR_ERROR('First argument to HTML_Select::loadArray is not a valid array');
        }
        if (isset($values)) {
            $this->setSelectedValues($values);
        }
        while (list($key, $value) = each($arr)) {
            $this->addOption($key, $value);
        }
        return true;
    }
    
    /**
     * Loads the options from an array with numeric keys, using the
     * array values as the form values as well as labels.
     * 
     * @param     array    $arr     Array of options
     * @param     mixed    $values  (optional) Array or comma delimited string of selected values
     * @since     1.2
     * @access    public
     * @return    PEAR_Error on error or true
     * @throws    PEAR_Error
     */
    function loadValueArray($arr, $values = null)
    {
        if (!is_array($arr)) {
            return new PEAR_ERROR("First argument to HTML_Select::loadArray is not a valid array");
        }
        if (isset($values)) {
            $this->setSelectedValues($values);
        }
        foreach ($arr as $value) {
            $this->addOption($value, $value);
        }
        return true;
    }
    
    /**
     * Loads the options from DB_result object
     * 
     * If no column names are specified the first two columns of the result are
     * used as the text and value columns respectively
     * @param     object    $result     DB_result object 
     * @param     string    $textCol    (optional) Name of column to display as the OPTION text 
     * @param     string    $valueCol   (optional) Name of column to use as the OPTION value 
     * @param     mixed     $values     (optional) Array or comma delimited string of selected values
     * @since     1.0
     * @access    public
     * @return    PEAR_Error on error or true
     * @throws    PEAR_Error
     */
    function loadDbResult(&$result, $textCol=null, $valueCol=null, $values=null)
    {
        include_once 'DB.php';
        
        if (!is_object($result) || (get_class($result) != "db_result" && 
            is_subclass_of($result, "db_result"))) {
            return new PEAR_ERROR("First argument to HTML_Select::loadDbResult is not a valid DB_result");
        }
         if (isset($values)) {
            $this->setSelectedValues($values);
        }
        $fetchMode = ($textCol && $valueCol) ? DB_FETCHMODE_ASSOC : DB_FETCHMODE_DEFAULT;
        while (is_array($row = $result->fetchRow($fetchMode)) ) {
            if ($fetchMode == DB_FETCHMODE_ASSOC) {
                $this->addOption($row[$textCol], $row[$valueCol]);
            } else {
                $this->addOption($row[0], $row[1]);
            }
        }
        return true;
    }
    
    /**
     * Queries a database and loads the options from the results
     *
     * @param     mixed     $conn       Either an existing DB connection or a valid dsn 
     * @param     string    $sql        SQL query string
     * @param     string    $textCol    (optional) Name of column to display as the OPTION text 
     * @param     string    $valueCol   (optional) Name of column to use as the OPTION value 
     * @param     mixed     $values     (optional) Array or comma delimited string of selected values
     * @since     1.1
     * @access    private
     * @return    void
     * @throws    
     */
    function loadQuery(&$conn, $sql, $textCol=null, $valueCol=null, $values=null)
    {
        include_once 'DB.php';
        
        if (is_string($conn)) {
            $dbConn = &DB::connect($conn, true);
            if (DB::isError($dbConn)) return $dbConn;
        } elseif (is_subclass_of($conn, "db_common")) {
            $dbConn = $conn;
        } else {
            return new PEAR_Error("Argument 1 of HTML_Select::loadQuery is not a valid type");
        }
        $result = @$dbConn->query($sql);
        if (DB::isError($result)) return $result;
        return $this->loadDbResult($result, $textCol, $valueCol, $values);
    }

    /**
     * Loads options from different types of data sources
     *
     * This method is a simulated overloaded method.  The arguments, other than the
     * first are optional and only mean something depending on the type of the first argument.
     * If the first argument is an array then all arguments are passed in order to loadArray.
     * If the first argument is a db_result then all arguments are passed in order to loadDbResult.
     * If the first argument is a string or a DB connection then all arguments are 
     * passed in order to loadQuery.
     * @param     mixed     $options     Options source currently supports assoc array or DB_result
     * @param     mixed     $param1     (optional) See function detail
     * @param     mixed     $param2     (optional) See function detail
     * @param     mixed     $param3     (optional) See function detail
     * @param     mixed     $param4     (optional) See function detail
     * @since     1.1
     * @access    public
     * @return    PEAR_Error on error or true
     * @throws    PEAR_Error
     */
    function load(&$options, $param1=null, $param2=null, $param3=null, $param4=null)
    {
        switch (true) {
            case is_array($options):
                return $this->loadArray($options, $param1);
                break;
            case (get_class($options) == "db_result" || is_subclass_of($options, "db_result")):
                return $this->loadDbResult($options, $param1, $param2, $param3);
                break;
            case (is_string($options) || is_subclass_of($options, "db_common")):
                return $this->loadQuery($options, $param1, $param2, $param3, $param4);
                break;
        }
    }
    
    /**
     * Returns the SELECT in HTML
     *
     * @since     1.0
     * @access    public
     * @return    string
     * @throws    
     */
    function toHtml()
    {
        $tabs = $this->_getTabs();
        $name = $this->_attributes['name'];
        $strHtml = $tabs;
        if ($this->_comment) {
            $strHtml .= "<!-- $this->_comment -->\n$tabs";
        }
        $strHtml .=
            '<select' . $this->_getAttrString($this->_attributes) . '>';
        foreach ($this->_options as $option) {
            if (@in_array($option['attr']['value'], $this->_values)) {
                $option['attr']['selected'] = 'selected';
            }
            $attrString = $this->_getAttrString($option['attr']);
            $strHtml .=
                '<option' . $attrString . '>' .
                htmlspecialchars($option['text']) . '</option>';
        }
        $strHtml .= '</select>';
        return $strHtml;
    }
    
}
?>
