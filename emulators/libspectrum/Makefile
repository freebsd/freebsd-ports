# New ports collection makefile for:	libspectrum
# Date created:			2003-10-27
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	libspectrum
PORTVERSION=	0.2.0.1
CATEGORIES=	emulators devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fuse-emulator

MAINTAINER=	kemm@in-line.ru
COMMENT=	Handling of ZX-Spectrum emulator files formats

USE_PERL5_BUILD=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_GLIB)
USE_GNOME=	glib12
.else
CONFIGURE_ARGS=	--without-glib
.endif

.if defined(WITH_GCRYPT) || exists(${LOCALBASE}/include/gcrypt.h)
LIB_DEPENDS=	gcrypt.6:${PORTSDIR}/security/libgcrypt
.endif

DOCS=		AUTHORS ChangeLog README THANKS doc/*

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITHOUT_GLIB=yes       don't use GLib"
	@${ECHO_MSG} "  WITH_GCRYPT=yes        use libgcrypt"
	@${ECHO_MSG} ""

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
