# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	mantis
PORTVERSION=	2.24.1
PORTEPOCH=	1
CATEGORIES=	databases www
MASTER_SITES=	SF/mantisbt/mantis-stable/${PORTVERSION}
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTNAME=	mantisbt-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Bug tracking system written in PHP

LICENSE=	GPLv2

USES=		php:flavors
USE_GITHUB=	nodefault
USE_PHP=	fileinfo filter hash json mbstring pcre session xml

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_GROUP=		PLUGINS
OPTIONS_GROUP_PLUGINS=	ACTIVITY ANNOUNCE COLORIZED CUSTOMREPORTER \
			EMAILREP EVENTLOG FLTBUGLST GAUGE JQUERYCHOSEN \
			JQUERYUI LIGHTBOX PIWIK SAMPLEAUTH SLACK \
			SNIPPETS SI TASKODROME TIMETRACKING
OPTIONS_DEFAULT=	MYSQL ${OPTIONS_GROUP_PLUGINS}
OPTIONS_SUB=		yes

# XXX: All of these should probably be either separate ports or at
# least subpackages...
ACTIVITY_DESC=		Shows bug notes by creation date
ANNOUNCE_DESC=		Announcements
COLORIZED_DESC=		Colorized Theme
CUSTOMREPORTER_DESC=	Allow the selection of a Reporter from a list
EMAILREP_DESC=		Allow to report an issue by sending an email
EVENTLOG_DESC=		Allow MantisBT components to log data
FLTBUGLST_DESC=		Allow to filter by a set of bug IDs
GAUGE_DESC=		Voting for tickets
JQUERYCHOSEN_DESC=	Support the Library Chosen to MantisBT
JQUERYUI_DESC=		jQuery UI library + Combobox
LIGHTBOX_DESC=		Plugin to open attachments using Lightbox
PIWIK_DESC=		Paste print screens directly
SAMPLEAUTH_DESC=	A sample authentication plugin
SLACK_DESC=		Slack integration
SNIPPETS_DESC=		Text snippets that can be pasted into text fields
SI_DESC=		Source control integration
TASKODROME_DESC=	Interactive scrum board
TIMETRACKING_DESC=	Time Tracking

ACTIVITY_GH_TUPLE=	mantisbt-plugins:Activity:99cf873396ebc3fec431c6746dae1a604768f322:activity/plugins/Activity
ANNOUNCE_GH_TUPLE=	mantisbt-plugins:Announce:v2.4.1:announce/plugins/Announce
COLORIZED_GH_TUPLE=	mantisbt-plugins:MantisBT-Colorized:f43dc4cc36e8851f8df1797116f904ccf5f1689d:colorized/css/themes/colorized
CUSTOMREPORTER_GH_TUPLE=	mantisbt-plugins:CustomReporter:v2.0.0:customreporter/plugins/CustomReporter
EMAILREP_GH_TUPLE=	mantisbt-plugins:EmailReporting:EmailReporting_0.10.1:emailrep/plugins/EmailReporting
EVENTLOG_GH_TUPLE=	mantisbt-plugins:EventLog:74fd03cf85a32088a0206bc73bb14ddbd148aed2:eventlog/plugins/EventLog
FLTBUGLST_GH_TUPLE=	mantisbt-plugins:FilterBugList:v2.1.0:fltbuglist/plugins/FilterBugList
GAUGE_GH_TUPLE=		mantisbt-plugins:GaugeSupport:9bd7e7dd1f496d28ee7ad2d831db3a276f996054:gauge/plugins/GaugeSupport
JQUERYCHOSEN_GH_TUPLE=	mantisbt-plugins:JqueryChosen:dc305e987ea3693bb92d22545ba23f3fc44d04c3:jquerychosen
JQUERYUI_GH_TUPLE=	mantisbt-plugins:jQuery-UI:ca77afa51166658b469dd11bfff7713485935bda:jqueryui
LIGHTBOX_GH_TUPLE=	mantisbt-plugins:Lightbox:f8220ba689378054ca433f718d909dc41a803def:lightbox/plugins/Lightbox
PIWIK_GH_TUPLE=		mantisbt-plugins:piwik:a2dba46836bdc07a80b8040e889ba0606f97415e:piwik
SAMPLEAUTH_GH_TUPLE=	mantisbt-plugins:SampleAuth:34856715f49a5c273f33e094c759c0e0b52b3912:sampleauth/plugins/SampleAuth
SLACK_GH_TUPLE=		mantisbt-plugins:Slack:9286d2eeeb8a986ed949e378711fef5f0bf182dc:slack/plugins/Slack
SNIPPETS_GH_TUPLE=	mantisbt-plugins:Snippets:v2.2.5:snippets/plugins/Snippets
SI_GH_TUPLE=		mantisbt-plugins:source-integration:v2.2.0:si
SI_USE=			php=curl
TASKODROME_GH_TUPLE=	mantisbt-plugins:Taskodrome:8bb3dd80af9190d636ce1117a291d9f8d0fec78e:taskodrome
TIMETRACKING_GH_TUPLE=	mantisbt-plugins:timetracking:3a560673d85e17651fc1994f5e09e2ae9df62336:timetracking

MYSQL_USE=	php=mysqli
PGSQL_USE=	php=pgsql

SUB_FILES=	pkg-message

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

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
	@${MV} ${WRKSRC_si}/Source* ${WRKSRC}/plugins

post-extract-TASKODROME-on:
	@${MV} ${WRKSRC_taskodrome}/Taskodrome ${WRKSRC}/plugins/

post-extract-TIMETRACKING-on:
	@${MV} ${WRKSRC_timetracking}/TimeTracking ${WRKSRC}/plugins/

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
