# ex:ts=8
# New ports collection makefile for:	elfio
# Date created:			Jul 26, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	elfio
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/ELFIO-sources/ELFIO-${PORTVERSION}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for reading and generating files in the ELF binary format

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal automake autoconf libtool
AUTOMAKE_ARGS=	-c -a
ACLOCAL_ARGS=	--automake-acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal

OPTIONE_DEFINE=	EXAMPLES DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
	@(${FIND} ${WRKSRC}/ -name Makefile.am | \
		${XARGS} ${REINPLACE_CMD} -E -e 's,(libELFIO)\.a,.libs/\1.so,g')

pre-configure:
	@(cd ${WRKSRC}/ && \
		${LIBTOOLIZE} --force --copy --automake)

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for f in elf11g.zip tutorial.docbook tutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/Examples/ -name "*.cpp" -exec ${INSTALL_DATA} {} \
		${EXAMPLESDIR}/ \;
.endif

.include <bsd.port.mk>
