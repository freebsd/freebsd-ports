# New ports collection makefile for:    helvis-1.8h2-
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	helvis
PORTVERSION=	1.8h2
PORTREVISION=	2
CATEGORIES=	korean editors
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/editor/HElvis/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/editor/HElvis/
DISTNAME=	helvis-1.8h2-

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	A clone of vi/ex, the standard UNIX editor, supporting Hangul

MAN1=		ctags.1 elvis.1 fmt.1 ref.1

post-patch:
	${ECHO_CMD} '.include "${FILESDIR}/Makefile.inc"' > ${WRKSRC}/${MAKEFILE}
	${CAT} ${WRKSRC}/${MAKEFILE}.mix >> ${WRKSRC}/${MAKEFILE}

post-install:
	@for manpage in \
	  ctags elvis fmt ref; \
	do \
	  ${INSTALL_MAN} ${WRKSRC}/doc/$${manpage}.man ${PREFIX}/man/man1/$${manpage}.1; \
	done

.include <bsd.port.mk>
