# New ports collection makefile for: tclcl
# Date created:		23 April 1999
# Whom:			obonilla@fisicc-ufm.edu
#
# $FreeBSD$
#

PORTNAME=	tclcl
PORTVERSION=	1.0b11
CATEGORIES=	devel tcl83 tk83
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTFILES=	tclcl-src-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/C++ interface used by ns and nam

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83 \
		otcl.1:${PORTSDIR}/lang/otcl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.3 --with-tk-ver=8.3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcl2c++ ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/otcldoc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtclcl.a ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libtclcl.a ${PREFIX}/lib/libTcl.a
.include <bsd.port.mk>
