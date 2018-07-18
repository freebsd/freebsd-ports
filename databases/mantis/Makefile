# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	mantis
PORTVERSION=	2.9.0
CATEGORIES=	databases www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bug tracking system written in PHP

NO_BUILD=	yes
USE_PHP=	hash pcre session xml
USE_GITHUB=	yes
GH_ACCOUNT=	mantisbt:DEFAULT \
		mantisbt:api_swaggerui \
		mantisbt:lib_adodb \
		mantisbt:lib_disposable \
		mantisbt:lib_parsedown \
		mantisbt:lib_phpmailer \
		mantisbt:lib_securimage
GH_PROJECT=	mantisbt:DEFAULT \
		swagger-ui:api_swaggerui \
		ADOdb:lib_adodb \
		disposable_email_checker:lib_disposable \
		parsedown:lib_parsedown \
		PHPMailer:lib_phpmailer \
		securimage:lib_securimage
GH_TAGNAME=	798792eebed2e699a98c4e94f4aeb4c35eba55f8:DEFAULT \
		0beaf61f94c3e6359ee0cdaf7b23ad4b365d761f:api_swaggerui \
		cc2c13e337f1441e3aa1e17497722c1cd98b281b:lib_adodb \
		6a7ddc0598810bdb91d270b489cec2e1033e047f:lib_disposable \
		20ff8bbb57205368b4b42d094642a3e52dac85fb:lib_parsedown \
		e066a6277ad41fcfdb8d3b8536aaa55ec9b6399b:lib_phpmailer \
		65d446e137db4fe84e7f7edb9e7b06fce521a63b:lib_securimage
GH_SUBDIR=	library/adodb:lib_adodb \
		library/disposable:lib_disposable \
		library/parsedown:lib_parsedown \
		library/phpmailer:lib_phpmailer \
		library/securimage:lib_securimage

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ACTIVITY ANNOUNCE COLORIZED CUSTOMREPORTER \
			EMAILREP EVENTLOG FLTBUGLST GAUGE JQUERYCHOSEN \
			JQUERYUI LIGHTBOX PIWIK SAMPLEAUTH SLACK \
			SNIPPETS SI TASKODROME TIMETRACKING
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SUB=		yes

ACTIVITY_DESC=		Shows bug notes by creation date
ACTIVITY_GH_ACCOUNT=	mantisbt-plugins:activity
ACTIVITY_GH_PROJECT=	Activity:activity
ACTIVITY_GH_TAGNAME=	99cf873396ebc3fec431c6746dae1a604768f322:activity
ACTIVITY_GH_SUBDIR=	plugins/Activity:activity

ANNOUNCE_DESC=		Announcements
ANNOUNCE_GH_ACCOUNT=	mantisbt-plugins:announce
ANNOUNCE_GH_PROJECT=	Announce:announce
ANNOUNCE_GH_TAGNAME=	f6a31c41e5dac73b99906cb3e6745def7f11f98a:announce
ANNOUNCE_GH_SUBDIR=	plugins/Announce:announce

COLORIZED_DESC=		Colorized Theme
COLORIZED_GH_ACCOUNT=	mantisbt-plugins:colorized
COLORIZED_GH_PROJECT=	MantisBT-Colorized:colorized
COLORIZED_GH_TAGNAME=	f43dc4cc36e8851f8df1797116f904ccf5f1689d:colorized
COLORIZED_GH_SUBDIR=	css/themes/colorized:colorized

CUSTOMREPORTER_DESC=		Allows the selection of a Reporter from a list
CUSTOMREPORTER_GH_ACCOUNT=	mantisbt-plugins:customreporter
CUSTOMREPORTER_GH_PROJECT=	CustomReporter:customreporter
CUSTOMREPORTER_GH_TAGNAME=	e9658eac2aa6c7e37609578e1d8bd676d22a3770:customreporter
CUSTOMREPORTER_GH_SUBDIR=	plugins/CustomReporter:customreporter

EMAILREP_DESC=		Allows to report an issue by sending an email
EMAILREP_GH_ACCOUNT=	mantisbt-plugins:emailrep
EMAILREP_GH_PROJECT=	EmailReporting:emailrep
EMAILREP_GH_TAGNAME=	81e7f0bda136f330ef6f535ad29b09b2c91dc0b4:emailrep
EMAILREP_GH_SUBDIR=	plugins/EmailReporting:emailrep

EVENTLOG_DESC=		Allows MantisBT components to log data
EVENTLOG_GH_ACCOUNT=	mantisbt-plugins:eventlog
EVENTLOG_GH_PROJECT=	EventLog:eventlog
EVENTLOG_GH_TAGNAME=	74fd03cf85a32088a0206bc73bb14ddbd148aed2:eventlog
EVENTLOG_GH_SUBDIR=	plugins/EventLog:eventlog

FLTBUGLST_DESC=		Allowing to filter by a set of bug IDs
FLTBUGLST_GH_ACCOUNT=	mantisbt-plugins:fltbuglst
FLTBUGLST_GH_PROJECT=	FilterBugList:fltbuglst
FLTBUGLST_GH_TAGNAME=	4de5242dcf3ced656cffbf14776ce41089c07e49:fltbuglst
FLTBUGLST_GH_SUBDIR=	plugins/FilterBugList:fltbuglst

GAUGE_DESC=		Voting for tickets
GAUGE_GH_ACCOUNT=	mantisbt-plugins:gauge
GAUGE_GH_PROJECT=	GaugeSupport:gauge
GAUGE_GH_TAGNAME=	5fd657c713c6ee5ff2ae8bfbedb30a700d38f2db:gauge
GAUGE_GH_SUBDIR=	plugins/GaugeSupport:gauge

JQUERYCHOSEN_DESC=		Support the Library Chosen to MantisBT
JQUERYCHOSEN_GH_ACCOUNT=	mantisbt-plugins:jquerychosen
JQUERYCHOSEN_GH_PROJECT=	JqueryChosen:jquerychosen
JQUERYCHOSEN_GH_TAGNAME=	dc305e987ea3693bb92d22545ba23f3fc44d04c3:jquerychosen

JQUERYUI_DESC=		jQuery UI library + Combobox
JQUERYUI_GH_ACCOUNT=	mantisbt-plugins:jqueryui
JQUERYUI_GH_PROJECT=	jQuery-UI:jqueryui
JQUERYUI_GH_TAGNAME=	ca77afa51166658b469dd11bfff7713485935bda:jqueryui

LIGHTBOX_DESC=		Plugin to open attachments using Lightbox
LIGHTBOX_GH_ACCOUNT=	mantisbt-plugins:lightbox
LIGHTBOX_GH_PROJECT=	Lightbox:lightbox
LIGHTBOX_GH_TAGNAME=	f8220ba689378054ca433f718d909dc41a803def:lightbox
LIGHTBOX_GH_SUBDIR=	plugins/Lightbox:lightbox

PIWIK_DESC=		Paste print screens directly
PIWIK_GH_ACCOUNT=	mantisbt-plugins:piwik
PIWIK_GH_PROJECT=	piwik:piwik
PIWIK_GH_TAGNAME=	a2dba46836bdc07a80b8040e889ba0606f97415e:piwik

SAMPLEAUTH_DESC=	A sample authentication plugin
SAMPLEAUTH_GH_ACCOUNT=	mantisbt-plugins:sampleauth
SAMPLEAUTH_GH_PROJECT=	SampleAuth:sampleauth
SAMPLEAUTH_GH_TAGNAME=	34856715f49a5c273f33e094c759c0e0b52b3912:sampleauth
SAMPLEAUTH_GH_SUBDIR=	plugins/SampleAuth:sampleauth

SLACK_DESC=		Slack integration
SLACK_GH_ACCOUNT=	mantisbt-plugins:slack
SLACK_GH_PROJECT=	Slack:slack
SLACK_GH_TAGNAME=	8aa67a830ca791936c05eede149d240d95579bcb:slack
SLACK_GH_SUBDIR=	plugins/Slack:slack

SNIPPETS_DESC=		Text snippets that can be pasted into text fields
SNIPPETS_GH_ACCOUNT=	mantisbt-plugins:snippets
SNIPPETS_GH_PROJECT=	snippets:snippets
SNIPPETS_GH_TAGNAME=	543b7a47640fa0a03b620ab08968d0e67a3d9b6f:snippets
SNIPPETS_GH_SUBDIR=	plugins/Snippets:snippets

SI_DESC=		Source control integration
SI_GH_ACCOUNT=		mantisbt-plugins:si
SI_GH_PROJECT=		source-integration:si
SI_GH_TAGNAME=		0c060a63850f1a97edd5ca63ddf99d29936f24a9:si
SI_USE=			php=curl

TASKODROME_DESC=	Interactive scrum board
TASKODROME_GH_ACCOUNT=	mantisbt-plugins:taskodrome
TASKODROME_GH_PROJECT=	Taskodrome:taskodrome
TASKODROME_GH_TAGNAME=	8e46633fdc303c32e6ce4777d8fabc1ce31cc589:taskodrome

TIMETRACKING_DESC=	Time Tracking
TIMETRACKING_GH_ACCOUNT=mantisbt-plugins:timetracking
TIMETRACKING_GH_PROJECT=timetracking:timetracking
TIMETRACKING_GH_TAGNAME=990ce27aba9a6f79fdfbe10f71c7b60c7b8cbe26:timetracking

MYSQL_DESC=	MySQL support
MYSQL_USE=	php=mysqli

PGSQL_DESC=	PostgreSQL support
PGSQL_USE=	php=pgsql

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-extract:
	@${MV} ${WRKSRC_api_swaggerui}/dist ${WRKSRC}/api/rest/swagger
	@${MV} ${WRKSRC}/api/rest/swagger/index.html ${WRKSRC}/api/rest/swagger/index.php

post-extract-COLORIZED-on:
	@${MV} ${WRKSRC_colorized}/colorized.css ${WRKSRC_colorized}/default.css
	@${CP} ${WRKSRC_colorized}/assets/screenshot-1.png ${WRKSRC_colorized}/colorized.png

post-extract-JQUERYCHOSEN-on:
	@${MV} ${WRKSRC_jquerychosen}/JqueryChosen ${WRKSRC}/plugins/

post-extract-JQUERYUI-on:
	@${MV} ${WRKSRC_jqueryui}/jQueryUI ${WRKSRC}/plugins/

post-extract-PIWIK-on:
	@${MV} ${WRKSRC_piwik}/Piwik ${WRKSRC}/plugins/

post-extract-SI-on:
	@${MV} ${WRKSRC_si}/Source ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceBitBucket ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceCgit ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceGithub ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceGitlab ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceGitphp ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceGitweb ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceHgWeb ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceSFSVN ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceSVN ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceViewVC ${WRKSRC}/plugins/
	@${MV} ${WRKSRC_si}/SourceWebSVN ${WRKSRC}/plugins/

post-extract-TASKODROME-on:
	@${MV} ${WRKSRC_taskodrome}/Taskodrome ${WRKSRC}/plugins/

post-extract-TIMETRACKING-on:
	@${MV} ${WRKSRC_timetracking}/TimeTracking ${WRKSRC}/plugins/

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
