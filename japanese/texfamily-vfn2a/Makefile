# New ports collection makefile for:	texfamily-vfn2a
# Date created:		13 June 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	texfamily-vfn2a
PORTVERSION=	1.3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/
DISTNAME=	vftool-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Virtual fonts for NTT JTeX

BUILD_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMF}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex \
		jtex:${PORTSDIR}/japanese/texfamily
RUN_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMF}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex \
		jtex:${PORTSDIR}/japanese/texfamily

MAKE_ENV=	JTEXTFMDIR=${LOCALBASE}/${TEXMFLOCAL}/fonts/tfm/muling/nttsub \
		PTEXTFMDIR=${LOCALBASE}/${TEXMF}/fonts/tfm/ptex

TEXMF=		share/texmf
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
FONTSDIR=	${TEXMFLOCAL}/fonts
PLIST_SUB=	FONTSDIR=${FONTSDIR} \
		MKTEXLSR=${MKTEXLSR}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}/vf/n2a
	${INSTALL_DATA} `${AWK} '/^%%FONTSDIR%%/ { gsub(/%%FONTSDIR%%/,"${WRKSRC}"); print }' < ${PLIST}` ${PREFIX}/${FONTSDIR}/vf/n2a

post-install:
	${MKTEXLSR}

.include <bsd.port.post.mk>
