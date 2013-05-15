# $FreeBSD$

PORTNAME=	kpathsea
PORTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20120701-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Path searching library for TeX

USE_XZ=		yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_TEX=	texlive
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES}
EXTRACT_FILES=	${DISTNAME}/build-aux \
		${DISTNAME}/texk/kpathsea
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea
GNU_CONFIGURE=	yes

INFO=	kpathsea
MAN1=	kpseaccess.1 kpsereadlink.1 kpsestat.1 kpsewhich.1 mktexlsr.1 \
	mktexmf.1 mktexpk.1 mktextfm.1 texhash.1

.include <bsd.port.mk>
