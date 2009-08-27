# New ports collection makefile for:	abi-compliance-checker
# Date created:		August 21, 2009
# Whom:	      		bf <bf1783@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.4
CATEGORIES=	devel perl5
MASTER_SITES=	http://ispras.linux-foundation.org/images/c/c1/
DISTFILES=	${PORTNAME:S/^a/A/}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bf1783@gmail.com
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

CPPFILT?=	c++filt
READELF?=	readelf

post-patch:
	${REINPLACE_CMD} -e "s|c++filt|${CPPFILT}|g" \
		-e "s|readelf|${READELF}|g" -e "s|g++|${CXX}|g" \
		-e "s|\"gcc|\"${CC}|g" -e "s|-shared|& -fPIC|g" ${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

regression-test: build
	@(cd ${WRKSRC} && ./${PORTNAME}.pl -test )

.include <bsd.port.mk>
