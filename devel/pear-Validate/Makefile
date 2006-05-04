# Ports collection makefile for:  pear-Validate
# Date created:			  25 August 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@php.net>)
#
# $FreeBSD$
#

PORTNAME=	Validate
PORTVERSION=	0.4.1
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Validation class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Validate.php Validate/Finance.php \
		Validate/Finance/IBAN.php Validate/AT.php Validate/CH.php \
		Validate/DE.php Validate/ES.php Validate/FR.php \
		Validate/NL.php Validate/PL.php Validate/ptBR.php \
		Validate/UK.php Validate/US.php

TESTS=		number.php date.php credit_card.php validate_AT.php \
		validate_CH.php validate_DE.php validate_NL.php \
		validate_UK.php validate_Finance.php

DOCS=		sample_multiple.php

DATA=		AT_postcodes.txt CH_postcodes.txt
DATAFILES=	Validate/AT.php Validate/CH.php

REINPLACE_ARGS=	-i ""

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

post-patch:
.for f in ${DATAFILES}
	@${REINPLACE_CMD} -e "s|@DATADIR@/Validate|${DATADIR}|g" ${WRKSRC}/${f}
.endfor

.include <bsd.port.post.mk>
