# New ports collection makefile for:	platex209-sjis
# Date created:		01 Jan 1998
# Whom:			Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	platex209
PORTVERSION=	1.0
PKGNAMESUFFIX=	-sjis
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/platex/
DISTNAME=	${PORTNAME}

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex${PKGNAMESUFFIX} \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex${PKGNAMESUFFIX}

MANUAL_PACKAGE_BUILD=	incompatible with other versions of platex209-*

TEXMF=		${PREFIX}/share/texmf

pre-configure:
	@(cd ${WRKSRC} ; \
	  for i in * ; do ${MV} $$i $$i.orig ; nkf -s $$i.orig > $$i ; done)

do-build:
	@(cd ${WRKSRC}; ptex -ini 'plplain.tex \dump')

do-install:
	${MKDIR} ${TEXMF}/tex/platex209/doc
	${MKDIR} ${TEXMF}/tex/platex209/general
	${MKDIR} ${TEXMF}/tex/platex209/sty
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${TEXMF}/tex/platex209
	@${INSTALL_DATA} ${WRKSRC}/*.doc ${TEXMF}/tex/platex209/doc
	@${INSTALL_DATA} ${WRKSRC}/*.tex ${TEXMF}/tex/platex209/general
	@${INSTALL_DATA} ${WRKSRC}/*.sty ${TEXMF}/tex/platex209/sty
	@${INSTALL_DATA} ${WRKSRC}/plplain.fmt ${TEXMF}/web2c/platex209.fmt
	${LN} -fs ptex ${PREFIX}/bin/platex209

.include <bsd.port.mk>
