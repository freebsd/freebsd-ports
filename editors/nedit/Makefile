# Created by: Daniel Eischen <deischen@freebsd.org>
# $FreeBSD$

PORTNAME=	nedit
PORTVERSION=	5.5
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nedit.org/pub/NEdit/v5_5/ \
		ftp://ftp.nedit.org/pub/NEdit/contrib/misc/ \
		http://www.nedit.org/ftp/v5_5/ \
		http://www.nedit.org/ftp/contrib/misc/
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/NEdit/v5_5/ \
		ftp://ftp.nluug.nl/pub/editors/NEdit/contrib/misc/ \
		ftp://cri.univ-tlse1.fr/pub/unix/nedit/NEdit/v5_5/ \
		ftp://cri.univ-tlse1.fr/pub/unix/nedit/NEdit/contrib/misc/ \
		http://www.nedit.org/ftp/v5_5/ \
		http://www.nedit.org/ftp/contrib/misc/
DISTFILES=	nedit-5.5-src.tar.bz2 nedit.app-defaults
EXTRACT_ONLY=	nedit-5.5-src.tar.bz2

MAINTAINER=	deischen@FreeBSD.org
COMMENT=	X11/Motif GUI text editor for programs and plain text files
LICENSE=	GPLv1

USES=		motif
USE_BZIP2=	yes
USE_XORG=	xpm
MAN1=		nclient.1 nedit.1
ALL_TARGET=	freebsd
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}

post-extract:
	${CP} ${DISTDIR}/nedit.app-defaults ${WRKSRC}/NEdit.ad

.include <bsd.port.mk>
