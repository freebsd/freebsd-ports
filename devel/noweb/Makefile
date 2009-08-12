# New ports collection makefile for:	noweb
# Date created:		29 July 1995
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	noweb
PORTVERSION=	2.11b
CATEGORIES=	devel
MASTER_SITES=	http://www.eecs.harvard.edu/~nr/noweb/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple, extensible literate-programming tool

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon
RUN_DEPENDS=	iconx:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
INSTALL_TARGET=	install-code install-man install-elisp
MAKE_JOBS_UNSAFE=	yes
MAN1=		cpif.1 htmltoc.1 nodefs.1 noindex.1 noroff.1 noroots.1 \
		notangle.1 noweb.1 nuweb2noweb.1 sl2h.1
MAN7=		nowebfilters.7 nowebstyle.7
MLINKS=		notangle.1 noweave.1	notangle.1 nountangle.1

NOWEBTEXDIR=	${PREFIX}/share/texmf-local/tex/plain/noweb
NOWEBLATEXDIR=	${PREFIX}/share/texmf-local/tex/latex/noweb

post-patch:
	@${TOUCH} ${WRKSRC}/c/modules.[ch]

post-build:
	@(cd ${WRKSRC} && ${SH} ${WRKSRC}/awkname awk)

post-install:
	@${MKDIR} ${NOWEBTEXDIR}
	${INSTALL_DATA} ${WRKSRC}/tex/nwmac.tex ${NOWEBTEXDIR}
	@${MKDIR} ${NOWEBLATEXDIR}
	${INSTALL_DATA} ${WRKSRC}/tex/noweb.sty ${NOWEBLATEXDIR}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
