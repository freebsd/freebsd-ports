# New ports collection makefile for:	wput
# Date created:				2 December 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	wput
PORTVERSION=	0.3.6
CATEGORIES=	ftp
MASTER_SITES=	http://itooktheredpill.dyndns.org/wput/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chip-set@mail.ru
COMMENT=	Uploads files or directories to a ftpserver with support of resuming

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in USAGE.examples TODO
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
