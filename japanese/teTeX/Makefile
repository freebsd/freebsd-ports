# $FreeBSD$

PORTNAME=	teTeX
PORTVERSION=	1.6
PORTREVISION=	6
CATEGORIES=	japanese print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite for Japanese (including pTeX and JTeX)

USE_TEX=	base texmf dvipsk ptex
.if !defined(WITHOUT_X11)
USE_TEX+=	xdvik
.endif
TEXMFLOCAL_LSR=	${LOCALBASE}/share/texmf-local/ls-R
TEXMFDISTDIR=	share/texmf-dist

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-build:
	@${DO_NADA}

do-install: #emtpy
	@${DO_NADA}

.include <bsd.port.post.mk>
