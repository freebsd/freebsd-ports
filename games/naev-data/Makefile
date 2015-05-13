# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	SF/${PROJECTHOST}/${PKGNAMEPREFIX}${PORTVERSION}/
PKGNAMEPREFIX=	naev-
DISTNAME=	${PORTNAME:S/^/n/}-${PORTVERSION}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PROJECTHOST}
EXTRACT_ONLY=	# empty

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Naev game data file

LICENSE=	GPLv2 GPLv3 CCBYv3 CCBYSAv3 PD
LICENSE_COMB=	multi
LICENSE_NAME_CCBYv3=	Creative Commons Attribution 3.0 Unported license
LICENSE_NAME_CCBYSAv3=	Creative Commons Attribution-ShareAlike 3.0 Unported license
LICENSE_NAME_PD=	Public Domain license
LICENSE_TEXT_CCBYv3=	The license: CCBYv3 (${LICENSE_NAME_CCBYv3}) is standard,\
	please read from the web: http://creativecommons.org/licenses/by/3.0/
LICENSE_TEXT_CCBYSAv3=	The license: CCBYSAv3 (${LICENSE_NAME_CCBYSAv3}) is standard,\
	please read from the web: http://creativecommons.org/licenses/by-sa/3.0/
LICENSE_TEXT_PD=	The license: PD (${LICENSE_NAME_PD}), please read possible explanation on the web:\
	http://www.teachingcopyright.org/handout/public-domain-faq
LICENSE_PERMS_CCBYv3=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CCBYSAv3=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_PD=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

PROJECTHOST=	${PKGNAMEPREFIX:S/-//}
NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/${PROJECTHOST}
PORTDATA=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
