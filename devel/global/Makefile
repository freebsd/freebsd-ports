# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	global
PORTVERSION=	6.2.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Source code tag system

GNU_CONFIGURE=	yes
USES=		perl5 libtool

INFO=		global

DOCS=		AUTHORS COPYING ChangeLog FAQ INSTALL LICENSE NEWS README THANKS

post-patch:
	${REINPLACE_CMD} -E 's,^(gtags_DATA = )AUTHORS .* THANKS( \\$$),\1\2,' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,;s,(@dirrm )share/doc/global,%%PORTDOCS%%\1%%DOCSDIR%%,;s,share/doc/global,%%PORTDOCS%%%%DOCSDIR%%,;s,^info/.+,,'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
