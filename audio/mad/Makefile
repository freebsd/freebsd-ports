# New ports collection makefile for:  mad
# Date created:        18 November 2000
# Whom:                Jason R. Mastaler <jason@mastaler.com>
#
# $FreeBSD$
#

PORTNAME=	mad
PORTVERSION=	0.14.2b
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	jason@mastaler.com

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_GNOMENG=	yes
WANT_GNOME=	yes

USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure libmad/configure libid3tag/configure
CONFIGURE_ARGS=	--enable-shared \
		--disable-debugging \
		--enable-sso \
		--enable-accuracy
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		abxtest.1 madplay.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+= --without-esd
.endif

post-patch:
# fix weird @INSTALL@ behavior caused by USE_AUTOCONF
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} -n 10 \
		${REINPLACE_CMD} -E -e 's|^(INSTALL[[:space:]]*=).*$$|\1 ${INSTALL_DATA}|'

.include <bsd.port.post.mk>
