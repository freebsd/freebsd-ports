# New ports collection makefile for:	IglooFTP
# Version required:			0.6.1
# Date created:				3 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		IglooFTP-0.6.1.src
PKGNAME=		IglooFTP-0.6.1
CATEGORIES=		ftp
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			ftp://littleigloo.org/pub/iglooftp/
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
			intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=		yes

WRKSRC=			${WRKDIR}/IglooFTP-0.6.1

do-build:
	@ cd ${WRKSRC}/src; ${MAKE}

do-install:
	@ cd ${WRKSRC}/src; ${MAKE} install
	@ ${RM} ${PREFIX}/share/IglooFTP/docs/LICENSE~

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/IglooFTP
.for file in AUTHORS BUGS COPYRIGHT THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/IglooFTP
.endfor
.endif

.include <bsd.port.mk>
