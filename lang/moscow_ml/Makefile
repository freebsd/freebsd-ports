# New ports collection makefile for:    moscow-ml
# Date created:         2 August 1998
# Whom:                 chuckr
#
# $FreeBSD$
#

PORTNAME=	moscow_ml
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/
DISTNAME=	mos20src

MAINTAINER=	chuckr@freefall.FreeBSD.org

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

MOSMLHOME=	$(PREFIX)/moscow_ml

ALL_TARGET=	world MOSMLHOME=$(MOSMLHOME)
INSTALL_TARGET=	install MOSMLHOME=$(MOSMLHOME)
WRKSRC=		${WRKDIR}/mosml/src
USE_PERL5=	yes

post-install:
	${SED} -e 's|^MOSMLHOME=.*|MOSMLHOME=${MOSMLHOME}|' \
	${WRKDIR}/mosml/tools/Makefile.stub > ${MOSMLHOME}/tools/Makefile.stub
	for file in ${WRKDIR}/mosml/doc/*; do \
	if [ -f $${file} ]; then \
	${INSTALL_DATA} $${file} ${MOSMLHOME}/doc; fi; done
	@cd ${WRKDIR}/mosml && \
	${TAR} -cf - examples | \
	${TAR} -xf - -C "${MOSMLHOME}"
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} "${MOSMLHOME}/examples"
	for file in ${MOSMLHOME}/bin/*; do \
	if [ -f $${file} ]; then \
	$(LN) -sf $${file} $(PREFIX)/bin; fi; done

.include <bsd.port.mk>
