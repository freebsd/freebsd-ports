# New ports collection makefile for:   systemc
# Date created:        15 December 2005
# Whom:                Daniel Thiele
#
# $FreeBSD$
#

PORTNAME=	systemc
PORTVERSION=	2.1.v1
PORTREVISION=	1
CATEGORIES=	cad devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	dthiele@gmx.net
COMMENT=	A modeling platform for system-level C++ models

RESTRICTED=	You have to register at http://www.systemc.org/account/register.php first

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_SCRIPT=	../configure
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX}/systemc ${CONFIGURE_TARGET}
CONFIGURE_WRKSRC=	${WRKSRC}/objdir
BUILD_WRKSRC=	${WRKSRC}/objdir
INSTALL_WRKSRC=	${WRKSRC}/objdir

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		is restricted. You have to register at http://www.systemc.org/account/register.php and download ${DISTFILES} from there first. Then put ${DISTFILES} into ${DISTDIR} and run make again
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CXXFLAGS+=	-O3
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

pre-configure:
	@${MKDIR} ${WRKSRC}/objdir
	@${REINPLACE_CMD} -e 's|\(OPT_CXXFLAGS="\).*"|\1${CXXFLAGS}"|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
