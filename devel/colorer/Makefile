# ex:ts=8
# Ports collection Makefile for:	colorer
# Date created:			Feb 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	colorer
PORTVERSION=	0.b2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Colorer-take5.beta2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A syntax highlighting and text parsing library

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		fop:${PORTSDIR}/textproc/fop \
		${LOCALBASE}/share/xsl/docbook/catalog:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/docbook-xsd/docbook.xsd:${PORTSDIR}/textproc/docbook-xsd \
		${LOCALBASE}/share/mathml-xsd/mathml2.xsd:${PORTSDIR}/textproc/mathml-xsd \
		${LOCALBASE}/share/xhtml1-xsd/xhtml1-strict.xsd:${PORTSDIR}/textproc/xhtml1-xsd

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_JAVA=	1.4+
NEED_JAVAC=	yes
ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET?=	library-linux
USE_GMAKE=	yes
PLIST_FILES=	bin/colorer lib/libcolorer.so

do-build:
	@(cd ${WRKSRC} && \
          ${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT} ${ANT_TARGET} ; \
	  cd distr/Colorer-take5-linux.beta2 ; \
	  ${REINPLACE_CMD} -e "s|make -C|${GMAKE} -C|" Makefile.in ; \
	  ${CHMOD} +x configure && ${SETENV} ${CONFIGURE_ENV} ./configure ; \
	  ${GMAKE} ${PORTNAME} \
	)

do-install:
	@(cd ${WRKSRC}/distr/Colorer-take5-linux.beta2 ; \
	  ${INSTALL_PROGRAM} src/colorer/colorer ${PREFIX}/bin ; \
	  ${INSTALL_DATA} src/libcolorer/libcolorer.so ${PREFIX}/lib ; \
	  ${MKDIR} ${DATADIR}/bin ; \
	  ${CP} -R hrc hrd ${DATADIR} ; \
	  ${CP} -R bin/4ever2take5 bin/apache bin/doclinks bin/xsd2hrc \
		bin/ue2hrc ${DATADIR}/bin ; \
	  ${MKDIR} ${PREFIX}/include/colorer ; \
	  ${INSTALL_DATA} catalog.xml LICENSE README ${DATADIR} ; \
	  cd src/shared ; \
	  ${TAR} cf - `${FIND} * -name "*.h"` | \
		${TAR} xfBp - -C ${PREFIX}/include/colorer \
	)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/distr/Colorer-take5-linux.beta2/doc/* ${DOCSDIR}
.endif
# generate plist
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/colorer -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/colorer -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${FIND} ${DOCSDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
