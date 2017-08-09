# New ports collection makefile for: Shell Script Frontend Tool (ssft linux library) 
# Date created:        11 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ssft
PORTVERSION=	1.0
CATEGORIES=	devel

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD ssft.sh script

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

MAN1=		ssft.sh.1
NO_BUILD=	yes

RUN_DEPENDS=	zenity:x11/zenity
BUILD_DEPENDS=	msgfmt:devel/gettext-tools

pre-build:
# Install .mo files
	for po in `cd ${WRKSRC}/po && ls *.po 2> /dev/null`; do \
	lang=`echo $$po | cut -d . -f1` ;\
	ldir="${WRKSRC}/locale/$$lang/LC_MESSAGES"; \
	${MKDIR} $${ldir};\
	msgfmt "${WRKSRC}/po/$${po}" -o "$${ldir}/${PORTNAME}.mo"; \
	${CHMOD} 0644 "$${ldir}/${PORTNAME}.mo";\
	done

do-install:pre-build
	${INSTALL_SCRIPT} ${WRKSRC}/src/* ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tests/* ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/* ${STAGEDIR}/${MANPREFIX}/man/man1
	${CP} -R   ${WRKSRC}/locale/* ${STAGEDIR}/${PREFIX}/share/locale
.include <bsd.port.mk>
