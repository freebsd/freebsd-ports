# New ports collection makefile for:   pth
# Date Created:			23 May 1999
# Whom:				Ralf S. Engelschall
#
# $FreeBSD$
#

PORTNAME=	pth
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	pth

MAINTAINER=	ports@FreeBSD.org

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/pth
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pthread \
		--enable-syscall-soft \
		--enable-optimize \
		--enable-batch \
		--includedir="${PREFIX}/include/pth" \
		--libdir="${PREFIX}/lib/pth"

MAN1=		pth-config.1 pthread-config.1
MAN3=		pth.3 pthread.3

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/pth.sh ${PREFIX}/etc/rc.d/000.pth.sh

test:
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
