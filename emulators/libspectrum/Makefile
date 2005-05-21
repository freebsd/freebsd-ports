# New ports collection makefile for:	libspectrum
# Date created:			2003-10-27
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	libspectrum
PORTVERSION=	0.2.2
CATEGORIES=	emulators devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fuse-emulator

MAINTAINER=	kemm@in-line.ru
COMMENT=	Handling of ZX-Spectrum emulator files formats

USE_PERL5_BUILD=	yes
WANT_GNOME=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

MAN3=		libspectrum.3

OPTIONS=	GLIB "Use GLib" on \
		GCRYPT "Use libgcrypt" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GLIB)
USE_GNOME=	glib20
.else
CONFIGURE_ARGS+=	--without-glib
.endif

.if defined(WITH_GCRYPT) || exists(${LOCALBASE}/include/gcrypt.h)
LIB_DEPENDS+=	gcrypt.13:${PORTSDIR}/security/libgcrypt
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS ChangeLog README THANKS doc/libspectrum.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
