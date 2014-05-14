# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdsreader
PORTVERSION=	0.3.2
CATEGORIES=	cad
MASTER_SITES=	http://home.netcom.com/~serbanp/
DISTNAME=	GDSreader.${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2 stream file to Postscript and HP/GL converter

PORTDOCS=	README README.povray ChangeLog
EXFILES=	layers.config test.gds layers.config.7HP.5ML \
		layers.config.5AM.4ML
PLIST_FILES=	bin/gdsreader bin/maptolayer \
		${EXFILES:S,^,${EXAMPLESDIR_REL}/,} \
		man/man1/gdsreader.1.gz man/man1/maptolayer.1.gz
PLIST_DIRS=	${EXAMPLESDIR_REL}

INSTALL_TARGET=	install install-data install-docs

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
