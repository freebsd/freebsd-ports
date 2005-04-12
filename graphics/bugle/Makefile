# New ports collection makefile for:	bugle
# Date created:			Jun 8, 2004
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	bugle
PORTVERSION=	0.0.20041123
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bugle

MAINTAINER=	erik@smluc.org
COMMENT=	A debugging library for OpenGL

MAN1=		gldb.1
MAN3=		bugle.3

USE_GCC=	3.4
USE_GL=		yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later to build. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
