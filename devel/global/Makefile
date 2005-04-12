# New ports collection makefile for:	global
# Date created:		20 June 2000
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	global
PORTVERSION=	4.8.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rui@ruilopes.com
COMMENT=	A source code tag system

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		gctags.1 global.1 gozilla.1 gtags.1 htags.1
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
