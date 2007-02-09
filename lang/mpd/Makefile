# New ports collection makefile for:	mpd
# Date Created:	2007-02-05
# Whom:		Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpd
PORTVERSION=	1.0.1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.arizona.edu/mpd/download/ \
		http://crypto.riken.go.jp/pub/NetBSD/packages/distfiles/mpd-language/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kaiw27@gmail.com
COMMENT=	A concurrent programming language

ONLY_FOR_ARCHS=	alpha i386
ONLY_FOR_ARCHS_REASON=	uses assembly code for the target machine

# net/mpd
NO_LATEST_LINK=	yes

USE_GMAKE=	yes

OPTIONS=	X11 "Enable X11 support" on

MAN1=		mpd.1 mpdl.1 mpdm.1 mpdprof.1
MAN3=		mpdanimator.3 mpdgetopt.3 mpdwin.3
MAN5=		mpdmap.5 mpdtrace.5

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment "
.else
PLIST_SUB+=	X11=""
USE_XLIB=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		"s%^(CCPATH =) .*%\1 `${WHICH} ${CC}`%; \
		 s%^(MPDSRC =) .*%\1 ${WRKSRC}%; \
		 s%^((MPD(CMD|LIB)|MAN[135]) =) /usr/local%\1 ${PREFIX}%" \
		 ${WRKSRC}/Configuration
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -Ee 's%^(XINCL =) .*%\1%' ${WRKSRC}/Configuration
.endif

pre-install:
	@${MKDIR} ${PREFIX}/lib/mpd

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -pR ${WRKSRC}/vsuite/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
