# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	m17n-docs
PORTVERSION=	1.5.5
CATEGORIES=	devel
MASTER_SITES=	http://www.m17n.org/m17n-lib-download/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	m17n library documentation

NO_BUILD=	yes

OPTIONS_DEFINE=	JAPANESE
JAPANESE_DESC=	Japanese documentation (HTML and PDF)

.include "${.CURDIR}/Makefile.man"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAPANESE}
PLIST_SUB+=	JAPANESE=""
.else
PLIST_SUB+=	JAPANESE="@comment "
.endif

DOCSDIR=	${PREFIX}/share/doc/m17n

do-install:
	${MKDIR} ${DOCSDIR}/en
	@${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/man/man1/|} ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${MAN3:S|^|${WRKSRC}/man/man3/|} ${MANPREFIX}/man/man3
	@${INSTALL_MAN} ${MAN5:S|^|${WRKSRC}/man/man5/|} ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/usr/latex/m17n-lib.pdf ${DOCSDIR}/en
	(cd ${WRKSRC}/usr/ && ${COPYTREE_SHARE} html ${DOCSDIR}/en/)
.if defined(WITH_JAPANESE)
	${MKDIR} ${DOCSDIR}/ja
	${INSTALL_MAN} ${WRKSRC}/ja/latex/m17n-lib.pdf ${DOCSDIR}/ja
	(cd ${WRKSRC}/ja/ && ${COPYTREE_SHARE} html ${DOCSDIR}/ja/)
.endif

.include <bsd.port.mk>
