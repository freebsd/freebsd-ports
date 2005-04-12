# New ports collection makefile for:	wput
# Date created:				2 December 2003
# Whom:					Nosov Artem <chip-set@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	wput
PORTVERSION=	0.5
CATEGORIES=	ftp
MASTER_SITES=	http://itooktheredpill.dyndns.org/wput/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	chip-set@mail.ru
COMMENT=	Uploads files or directories to a ftpserver with support of resuming

PORTDOCS=	TODO ChangeLog

USE_GETOPT_LONG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LIBS="${LDFLAGS}"

PLIST_FILES=	bin/wput
MANCOMPRESSED=	yes
MAN1=		wput.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
