# New ports collection makefile for:    eiffel
# Date created:         Thu Sep 14 11:10:01 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	eiffel
PORTVERSION=	13a
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cm.cf.ac.uk/pub/Eiffel/SIG/Eiffel-S-1.3/BSD/
DISTNAME=	${PORTNAME}s${PORTVERSION}
EXTRACT_SUFX=	.freebsd.tar.gz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

FILES=		IAFA-PACKAGE bin doc eiffels.20 examples install.freebsd \
		introduction library readme.1st register.txt run3 \
		sharewar.txt source

do-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${FILESDIR}/ecc.sh > ${WRKSRC}/ecc.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ecc.sh ${PREFIX}/bin/ecc
	@${MKDIR} ${PREFIX}/eiffel
	cd ${WRKSRC} && pax -rw ${FILES} ${PREFIX}/eiffel

.include <bsd.port.mk>
