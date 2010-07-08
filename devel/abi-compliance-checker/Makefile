# New ports collection makefile for:	abi-compliance-checker
# Date created:		August 21, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.16
CATEGORIES=	devel perl5
MASTER_SITES=	http://ispras.linux-foundation.org/images/8/8d/
DISTFILES=	${PORTNAME:S/^a/A/}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

CPPFILT?=	c++filt
READELF?=	readelf

post-patch:
	${REINPLACE_CMD} \
		-e "\%my% { \
			s%\"c++filt\"%\"${CPPFILT}\"%g; \
			s%\"readelf\"%\"${READELF}\"%g; \
			s%\"g++\"%\"${CXX}\"%g; \
			s%\"gcc\"%\"${CC}\"%g; }" \
		-e "\%search_for% { \
			s%\"g++\"%\"${CXX}\"%g; \
			s%\"gcc\"%\"${CC}\"%g; }" \
		-e "s%-shared%& -fPIC%g" \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

test: build
	@(cd ${WRKSRC} && ./${PORTNAME}.pl -test )

.include <bsd.port.mk>
