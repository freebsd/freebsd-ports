# New ports collection makefile for:	teTeX
# Date created:		3 June 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX
PORTVERSION=	1.5
CATEGORIES=	japanese print
MASTER_SITES=	# empty
PKGNAMEPREFIX=	ja-
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite for Japanese (including pTeX and JTeX)

RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		tex:${PORTSDIR}/print/teTeX-base \
		ptex:${PORTSDIR}/japanese/ptex-tetex \
		dvips:${PORTSDIR}/japanese/dvipsk \
		xdvi:${PORTSDIR}/japanese/xdvik \
		jtex:${PORTSDIR}/japanese/texfamily \
		${JTEXVF}:${PORTSDIR}/japanese/texfamily-vfn2a

JTEXVF=		${LOCALBASE}/share/texmf-local/fonts/vf/n2a/dmjsy5.vf
TEXMFLOCAL_LSR=	${LOCALBASE}/share/texmf-local/ls-R
TEXMFDISTDIR=	share/texmf-dist

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

.include <bsd.port.pre.mk>

do-build:
	@${DO_NADA}

do-install: #emtpy
	@${DO_NADA}

.include <bsd.port.post.mk>
