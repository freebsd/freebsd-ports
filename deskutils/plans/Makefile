# New ports collection makefile for:	plans
# Date created:				2004-12-17
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	plans
PORTVERSION=	7.9.1
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.planscalendar.com/release/:plans \
		http://www.planscalendar.com/addons/:addons \
		http://www.freebsd.org/gifs/:logo
DISTNAME=	${PORTNAME}_${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:plans \
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

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A Good Web Calendar

BUILD_DEPENDS=	${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

WWWDOCROOT?=	www
PLANSSUBDIR?=	plans
PLANSDIR?=	${WWWDOCROOT}/${PLANSSUBDIR}
PLIST_SUB+=	DIR=${PLANSDIR}
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
DIR=		${PREFIX}/${PLANSDIR}
SUB_LIST+=	DIR=${DIR}

.include <bsd.port.pre.mk> # Need to exists() work

post-extract:
	@${CP} ${_DISTDIR}/powerani.gif ${WRKSRC}/theme/graphics/freebsd.gif
	@${CP} ${_DISTDIR}/*.pl ${WRKSRC}/
	@for i in ${WRKSRC}/data/*xml ${WRKSRC}/*config.pl; do ${MV} $$i $$i.default; done
	@${SED} -e 's/iso-8859-1/utf-8/' ${WRKSRC}/us_english.pl > ${WRKSRC}/us_english_utf8.pl

post-patch:
	@${RM} -f ${WRKSRC}/theme/plans.template.orig

do-install:
	@${INSTALL} -d ${DIR}
	@${CP} -nR ${WRKSRC}/ ${DIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DIR}/
	@${FIND} ${DIR} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${DIR} -name '*.cgi' -exec ${CHMOD} 755 {} \;
	@${FIND} ${DIR} -name '*.xml' -exec ${CHMOD} 664 {} \;

post-install:
	@for i in ${DIR}/data/*default ${DIR}/*default; do ${CP} -np $$i $${i%.default}; done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
