# New ports collection makefile for:	lib765
# Date created:			2003-10-27
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	lib765
PORTVERSION=	0.4.2
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.demon.co.uk/Unix/LibDsk/

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Emulation of uPD765a Floppy Disc Controller

LICENSE=	LGPL20

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

OPTIONS=	LIBDSK "With LIBDSK support (recommended)" on

.include <bsd.port.pre.mk>

.if defined(WITH_LIBDSK)
CONFIGURE_ARGS+=	--with-libdsk --with-libdsk-path=${LOCALBASE}
LIB_DEPENDS+=		dsk.5:${PORTSDIR}/emulators/libdsk
.else
CONFIGURE_ARGS+=	--without-libdsk
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog doc/765.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
