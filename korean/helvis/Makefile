# New ports collection makefile for:    helvis-1.8h2-
# Version required:     1.8h2-
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

DISTNAME=	helvis-1.8h2-
PKGNAME=	ko-helvis-1.8h2-
CATEGORIES=	korean editors
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/editor/HElvis/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/editor/HElvis/

MAINTAINER=	junker@jazz.snu.ac.kr

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
