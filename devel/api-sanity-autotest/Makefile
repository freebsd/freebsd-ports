# New ports collection makefile for:	api-sanity-autotest
# Date created:		February 16, 2009
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	api-sanity-autotest
PORTVERSION=	1.12.3
CATEGORIES=	devel perl5
MASTER_SITES=	http://linuxtesting.org/downloads/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Quickly generate sanity tests for the API of a C/C++ shared library

LICENSE=	LGPL20 GPLv2
LICENSE_COMB=	dual

NO_BUILD=	yes
USE_PERL5_RUN=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

CPPFILT?=	c++filt
READELF?=	readelf

post-patch:
	@${REINPLACE_CMD} \
		-e "\|ArCmd =|s|=.*|= \"${AR}\";|" \
		-e "\|CPP_FILT =|s|=.*|= \"${CPPFILT}\";|" \
		-e "\|GCC_PATH =|s|=.*|= \"${CC}\";|" \
		-e "\|GPP_PATH =|s|=.*|= \"${CXX}\";|" \
		-e "\|ObjdumpCmd =|s|=.*|= \"${OBJDUMP}\";|" \
		-e "\|ReadelfCmd =|s|=.*|= \"${READELF}\";|" \
		-e "s|-shared|& -fPIC|g" \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin

check regression-test test: build
	@(cd ${WRKSRC} && ./${PORTNAME}.pl -test )

.ifndef(NOPORTDOCS)
PORTDOCS=	Changes.html Descriptor.html Options.html Readme.html SpecType.html

post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR})

.endif
.include <bsd.port.mk>
