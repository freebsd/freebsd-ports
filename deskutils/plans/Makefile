# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	plans
PORTVERSION=	8.2.1
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.planscalendar.com/release/:plans \
		http://www.planscalendar.com/addons/:addons \
		http://www.freebsd.org/gifs/:logo CENKES:plans,addons,logo
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

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A Good Web Calendar

BUILD_DEPENDS=	p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

SUB_FILES=	pkg-message

NO_STAGE=	yes
post-extract:
	@${CP} ${_DISTDIR}/powerani.gif ${WRKSRC}/theme/graphics/freebsd.gif
	@${CP} ${_DISTDIR}/*.pl ${WRKSRC}/
	@${RM} -rf ${WRKSRC}/theme/us_english.pl
	@for i in ${WRKSRC}/data/*xml ${WRKSRC}/*config.pl;\
		do ${MV} $$i $$i.default; done
	@${SED} -e 's/iso-8859-1/utf-8/' ${WRKSRC}/us_english.pl >\
		${WRKSRC}/us_english_utf8.pl
	@${TOUCH} ${WRKSRC}/theme/ical/.keep_me

post-patch:
	@${RM} -f ${WRKSRC}/theme/plans.template.orig

do-install:
	@${INSTALL} -d ${WWWDIR}/
	@${CP} -nR ${WRKSRC}/ ${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	@${FIND} ${WWWDIR} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${WWWDIR} -name '*.cgi' -exec ${CHMOD} 755 {} \;
	@${FIND} ${WWWDIR} -name '*.xml' -exec ${CHMOD} 664 {} \;
	@for i in ${WWWDIR}/data/*default ${WWWDIR}/*default; do\
		${CP} -np $$i $${i%.default} || ${TRUE} ; done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
