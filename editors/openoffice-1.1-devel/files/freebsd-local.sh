#!/bin/sh
#
# $FreeBSD $

save_common_xcu() {
sed 's/^X//' > $OOHOME/tmp/Common.xcu << 'END-of-Common.xcu'
X<?xml version="1.0" encoding="UTF-8"?>
X<oor:component-data xmlns:oor="http://openoffice.org/2001/registry" xmlns:xs="http://www.w3.org/2001/XMLSchema" oor:name="Common" oor:package="org.openoffice.Office">
X <node oor:name="Internal">
X  <prop oor:name="CurrentTempURL" oor:type="xs:string">
X   <value/>
X  </prop>
X </node>
X <node oor:name="Misc">
X  <prop oor:name="FirstRun" oor:type="xs:boolean">
X   <value>true</value>
X  </prop>
X </node>
X <node oor:name="ExternalApps">
X  <prop oor:name="file" oor:type="xs:string">
X   <value/>
X  </prop>
X  <prop oor:name="ftp" oor:type="xs:string">
X   <value/>
X  </prop>
X  <prop oor:name="http" oor:type="xs:string">
X   <value>%%mozilla%%</value>
X  </prop>
X  <prop oor:name="https" oor:type="xs:string">
X   <value/>
X  </prop>
X  <prop oor:name="mailto" oor:type="xs:string">
X   <value/>
X  </prop>
X </node>
X</oor:component-data>
END-of-Common.xcu
mozilla=`which mozilla`;
if [ $? -eq 0 ]; then
	sed -i orig -e 's#%%mozilla%%#'$mozilla'#g' $OOHOME/tmp/Common.xcu
fi
mozilla=`which linux-mozilla`;
if [ $? -eq 0 ]; then
	sed -i orig -e 's#%%mozilla%%#'$mozilla'#g' $OOHOME/tmp/Common.xcu
fi
mv $OOHOME/tmp/Common.xcu $OOHOME/user/registry/data/org/openoffice/Office
}

#
# Set default lang to en_US.ISO8859-15
#
if [ ! $LANG ]; then
	export LANG=en_US.ISO8859-15
fi

#
# Create soffice.cfg if it does not exist.
#
if [ ! -z $OOHOME ] && [ -e $OOHOME/setup ]; then
	if [ ! -d $OOHOME/user/config/soffice.cfg ]; then
		mkdir $OOHOME/user/config/soffice.cfg
	fi
fi

#
# Detect installed mozilla
#
if [ ! -z $OOHOME ] && [ ! -e $OOHOME/user/registry/data/org/openoffice/Office/Common.xcu ]; then
	mkdir -p $OOHOME/tmp;
	save_common_xcu;
fi
