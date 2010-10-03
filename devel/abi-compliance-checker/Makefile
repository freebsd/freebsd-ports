# New ports collection makefile for:	abi-compliance-checker
# Date created:		August 21, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abi-compliance-checker
PORTVERSION=	1.21.6
CATEGORIES=	devel perl5
MASTER_SITES=	http://linuxtesting.org/downloads/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks binary compatibility of two versions of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

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
		-e "s%detailes%details%g" \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

test: build
	@(cd ${WRKSRC} && ./${PORTNAME}.pl -test )

.ifndef(NOPORTDOCS)
PORTDOCS=	README.html

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.html ${DOCSDIR}

.endif
.include <bsd.port.mk>
