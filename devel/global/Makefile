# New ports collection makefile for:	global
# Date created:		20 June 2000
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	global
PORTVERSION=	6.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A source code tag system

GNU_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		global.1 globash.1 gozilla.1 gtags.1 gtags-cscope.1 htags.1
INFO=		global

post-patch:
	${REINPLACE_CMD} -E 's,^(gtags_DATA = )AUTHORS .* THANKS( \\$$),\1\2,' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/global
.for file in AUTHORS COPYING ChangeLog FAQ INSTALL LICENSE NEWS README \
		THANKS
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/global
.endfor
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX}|${SED} -E 's,.*share/nls/.+$$,,;s,(@dirrm )share/doc/global,%%PORTDOCS%%\1%%DOCSDIR%%,;s,share/doc/global,%%PORTDOCS%%%%DOCSDIR%%,;s,^info/.+,,'|${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
