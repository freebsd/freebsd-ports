# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	plans
PORTVERSION=	8.2.1
PORTREVISION=	3
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.planscalendar.com/release/:plans \
		http://www.planscalendar.com/addons/:addons \
		http://www.freebsd.org/gifs/:logo
DISTNAME=	${PORTNAME}_${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:plans \
		cz_czech.pl:addons \
		danish.pl:addons \
		nl_dutch.pl:addons \
		fr_french.pl:addons \
		de_german.pl:addons \
		it_italian.pl:addons \
		sp_spanish.pl:addons \
		zh_tw.pl:addons \
		powerani.gif:logo
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Good Web Calendar

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-CGI-Session>=0:www/p5-CGI-Session
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix zip
USE_PERL5=	run
SHEBANG_FILES=	email_reminders.cgi plans.cgi plans_check.cgi upcoming_events.cgi
NO_BUILD=	yes
NO_ARCH=	yes

SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}
SHAREMODE=	644

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

SUB_FILES=	pkg-message

post-extract:
	@${CP} ${_DISTDIR}/powerani.gif ${WRKSRC}/theme/graphics/freebsd.gif
	@${CP} ${_DISTDIR}/*.pl ${WRKSRC}/
	@${RM} -r ${WRKSRC}/theme/us_english.pl
	@for i in ${WRKSRC}/data/*xml ${WRKSRC}/*config.pl;\
		do ${MV} $$i $$i.sample; done
	@${SED} -e 's/iso-8859-1/utf-8/' ${WRKSRC}/us_english.pl >\
		${WRKSRC}/us_english_utf8.pl
	@${TOUCH} ${WRKSRC}/theme/ical/.keep_me

post-patch:
	@${RM} ${WRKSRC}/theme/plans.template.orig

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@${FIND} ${STAGEDIR}${WWWDIR} -name '*.cgi' -exec ${CHMOD} 755 {} \;
	@${FIND} ${STAGEDIR}${WWWDIR} -name '*.xml.sample' -exec ${CHMOD} 664 {} \;

.include <bsd.port.mk>
