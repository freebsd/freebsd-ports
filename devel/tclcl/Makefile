# New ports collection makefile for: tclcl
# Date created:		23 April 1999
# Whom:			obonilla@fisicc-ufm.edu
#
# $FreeBSD$
#

PORTNAME=	tclcl
PORTVERSION=	1.16
CATEGORIES=	devel tcl84 tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	otcl-tclcl
DISTFILES=	tclcl-src-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/C++ interface used by ns and nam

LIB_DEPENDS=	tk84:${PORTSDIR}/x11-toolkits/tk84 \
		otcl:${PORTSDIR}/lang/otcl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.4 --with-tk-ver=8.4

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcl2c++ ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/otcldoc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtclcl.a ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libtclcl.a ${PREFIX}/lib/libTcl.a
.include <bsd.port.post.mk>
