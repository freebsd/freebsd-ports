# Ports collection makefile for:	huc
# Date created:			1 December 2003
# Whom:				Frederic Cambus
#
# $FreeBSD$
#

PORTNAME=	huc
PORTVERSION=	3.20
PORTREVISION=	1
CATEGORIES=	lang emulators
MASTER_SITES=	http://www.zeograd.com/download/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PC Engine C compiler which can create ROMs (hucard) or CD images

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

do-install:
.for file in huc isolink nesasm pceas pcxtool
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${TAR} -C ${WRKSRC}/include --exclude "CVS" -cf - . | \
		${TAR} -C ${PREFIX}/include/${PORTNAME} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREMODE} ${PREFIX}/include/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude "CVS" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREMODE} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
