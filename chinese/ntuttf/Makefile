# New ports collection makefile for:	NTU Chinese TrueType fonts
# Date created:		11 April 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ntuttf
PORTVERSION=	1.0
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://cle.linux.org.tw/pub/fonts/ttf/unicode/ntu/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/ntuttf/
DISTFILES=	NTU_FS_M.TTF NTU_KAI.TTF NTU_LI_M.TTF NTU_MB.TTF \
		NTU_MM.TTF NTU_MR.TTF NTU_TW.TTF
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Seven Chinese Big5 TrueType fonts made by NTU

NO_BUILD=	yes

TTF=		${DISTFILES}

do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	@${INSTALL_DATA} ${DISTDIR}/${i} ${FONTSDIR}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
