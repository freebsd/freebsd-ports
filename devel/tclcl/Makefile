# New ports collection makefile for: tclcl
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	tclcl
PORTVERSION=	1.0b11
CATEGORIES=	devel tcl83 tk83
MASTER_SITES=	http://www.isi.edu/nsnam/dist/
DISTFILES=	tclcl-src-${PORTVERSION}.tar.gz

MAINTAINER=	obonilla@fisicc-ufm.edu

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
