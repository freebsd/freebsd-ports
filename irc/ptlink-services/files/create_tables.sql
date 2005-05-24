DROP TABLE IF EXISTS nickserv;
CREATE TABLE nickserv (
  snid INT UNSIGNED NOT NULL auto_increment,
  nick varchar(32) NOT NULL default '',
  t_reg datetime NOT NULL,
  t_ident datetime NOT NULL,
  t_seen datetime NOT NULL,
  t_sign datetime NOT NULL,
  pass varchar(32) default NULL,
  email varchar(64) default NULL,
  url varchar(64) default NULL,
  imid varchar(64) default NULL,
  location varchar(64) default NULL,
  ontime INT UNSIGNED NOT NULL default '0',
  username varchar(32) NOT NULL default '0',
  realhost varchar(64) default NULL,
  info varchar(64) default NULL,
  nmask INT UNSIGNED default NULL,
  ajoin varchar(128) default NULL,
  status int NOT NULL default '0',
  flags int NOT NULL default '0',
  securitycode varchar(32) default NULL,
  lang int NOT NULL default '0',
  master_snid INT UNSIGNED NOT NULL default '0',
  PRIMARY KEY  (snid),
  UNIQUE KEY nick (nick)
) Type = InnoDB;

DROP TABLE IF EXISTS memoserv;
CREATE TABLE memoserv(
  smid INT UNSIGNED NOT NULL auto_increment,
  owner_snid INT UNSIGNED NOT NULL,
  sender_snid INT UNSIGNED NOT NULL,
  sender_name varchar(32) NULL, # the sender_snid may drop
  flags INT UNSIGNED NOT NULL,
  t_send DATETIME NOT NULL,
  message VARCHAR(255) NOT NULL,
  PRIMARY KEY (smid),
  KEY smid (smid)
) Type = InnoDB;

# Table structure for table `chanserv`
DROP TABLE IF EXISTS chanserv;
CREATE TABLE chanserv (
  scid INT UNSIGNED NOT NULL auto_increment,
  name varchar(64) NOT NULL default '',
  url varchar(64) default NULL,
  email varchar(64) default NULL,
  founder INT UNSIGNED NOT NULL default '0',
  successor INT UNSIGNED NOT NULL default '0',
  last_topic text,
  last_topic_setter varchar(32) default NULL,
  t_ltopic datetime NOT NULL,
  t_reg datetime NOT NULL,
  t_last_use datetime NOT NULL,
  mlock varchar(64) default NULL,
  status int(2) NOT NULL default '0',
  flags int(2) NOT NULL default '0',
  entrymsg varchar(255) default NULL,
  cdesc varchar(255) default NULL,
  t_maxusers datetime NOT NULL,
  maxusers int(5) NOT NULL default '0',
  PRIMARY KEY  (scid),
  UNIQUE KEY name (name)
) Type = InnoDB;

# This is just a temporary table to map access list levels
# to chan roles
DROP TABLE IF EXISTS cs_role_temp;
CREATE TABLE cs_role_temp (
  scid INT UNSIGNED NOT NULL,
  snid INT UNSIGNED NOT NULL,
  who INT UNSIGNED NOT NULL,
  rtype INT NOT NULL
) Type = InnoDB;

DROP TABLE IF EXISTS ircsvs_tables;
CREATE TABLE ircsvs_tables(
  name varchar(32) NOT NULL,
  version INT UNSIGNED NOT NULL,
  inst_time datetime NOT NULL
) Type = InnoDB;

# this tables are installed by services2 
INSERT INTO ircsvs_tables VALUES ("mysql", 1 , NOW());
INSERT INTO ircsvs_tables VALUES ("nickserv", 1 , NOW());
INSERT INTO ircsvs_tables VALUES ("chanserv", 1 , NOW());
INSERT INTO ircsvs_tables VALUES ("memoserv", 1 , NOW());

