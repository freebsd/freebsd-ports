# New ports collection makefile for:   pth
# Date Created:			23 May 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	pth
PORTVERSION=	2.0.0
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	pth

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Portable Threads

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/pth
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pthread \
		--enable-syscall-soft \
		--enable-optimize \
		--enable-batch \
		--includedir="${PREFIX}/include/pth" \
		--libdir="${PREFIX}/lib/pth"
USE_REINPLACE=	yes

MAN1=		pth-config.1 pthread-config.1
MAN3=		pth.3 pthread.3

post-patch:
	${REINPLACE_CMD} -e \
		"s,-funroll-loops -fstrength-reduce -fomit-frame-pointer -ffast-math,${CFLAGS}," \
		${WRKSRC}/configure
post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/pth.sh ${PREFIX}/etc/rc.d/000.pth.sh

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
