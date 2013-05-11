# $FreeBSD$

PORTNAME=	teTeX
PORTVERSION=	1.6
PORTREVISION=	5
CATEGORIES=	japanese print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite for Japanese (including pTeX and JTeX)

RUN_DEPENDS=	jtex:${PORTSDIR}/japanese/texfamily \
		${JTEXVF}:${PORTSDIR}/japanese/texfamily-vfn2a

USE_TEX=	base texmf dvipsk ptex
.if !defined(WITHOUT_X11)
USE_TEX+=	xdvik
.endif
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
