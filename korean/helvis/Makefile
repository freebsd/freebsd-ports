# New ports collection makefile for:    helvis-1.8h2-
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	helvis
PORTVERSION=	1.8h2
PORTREVISION=	1
CATEGORIES=	korean editors
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/editor/HElvis/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/editor/HElvis/
DISTNAME=	helvis-1.8h2-

MAINTAINER=	cjh@FreeBSD.org

MAN1=		ctags.1 elvis.1 elvprsv.1 elvrec.1 fmt.1 ref.1

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@for manpage in \
	  ctags elvis elvprsv elvrec fmt ref; \
	do \
	  ${INSTALL_MAN} ${WRKSRC}/doc/$${manpage}.man ${PREFIX}/man/man1/$${manpage}.1; \
	done

.include <bsd.port.mk>
