# ex:ts=8
#
# New ports collection makefile for:	cyclone
# Date created:		2002/01/06
# Whom:			AlanE <ports@geeksrus.net> et al
#
# $FreeBSD$
#

PORTNAME=	cyclone
PORTVERSION=	0.2
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.cornell.edu/projects/cyclone/ \
		http://www.research.att.com/projects/cyclone/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-${PORTVERSION}-docs.tar.gz

MAINTAINER=	ports@geeksrus.net

USE_GMAKE=	yes
USE_GCC295=	yes
NO_PACKAGE=	'Neither CC nor CFLAGS safe.'
WRKSRC=		${WRKDIR}/${PORTNAME}
CYCBINDIR=	${PREFIX}/bin
CYCINCDIR=	${PREFIX}/include/cyclone
CYCLIBDIR=	${PREFIX}/lib/cyclone
ALL_TARGET=	build
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S/^${PREFIX}\///}

pre-everything::
	@${ECHO_MSG} '>>>'
	@${ECHO_MSG} '>>> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS.'
	@${ECHO_MSG} '>>>'

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${PERL} -pi -e \
		's/-O3/-O/'
.endif

do-configure:
	@cd ${CONFIGURE_WRKSRC} && ${ECHO} y | ./configure ${CONFIGURE_ARGS}

post-build:
.for target in cyclone_src update build test
	@cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} ${target}
.endfor

post-install:
.for prog in cyclone cycbison cyclex cycflex
	@${CHOWN} ${BINOWN}:${BINGRP} ${CYCBINDIR}/${prog}
	@${CHMOD} ${BINMODE} ${CYCBINDIR}/${prog}
.endfor
	@${RANLIB} ${CYCLIBDIR}/*.a
	@${CHOWN} -R ${INCOWN}:${INCGRP} ${CYCINCDIR}
	@${CHOWN} -R ${LIBOWN}:${LIBGRP} ${CYCLIBDIR}
	@${CHMOD} -R ${INCMODE} ${CYCINCDIR}
	@${CHMOD} -R ${LIBMODE} ${CYCLIBDIR}
	@${FIND} ${CYCINCDIR} ${CYCLIBDIR} -type d | ${XARGS} ${CHMOD} +x
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/online-manual
	@${INSTALL_DATA} ${WRKDIR}/*.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/online-manual/* ${DOCSDIR}/online-manual
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/bash) || !exists(${LOCALBASE}/bin/ksh)
BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash2

CONFIGURE_ARGS=	-sh ${LOCALBASE}/bin/bash
.else
BUILD_DEPENDS+=	ksh:${PORTSDIR}/shells/pdksh

CONFIGURE_ARGS=	-sh ${LOCALBASE}/bin/ksh
.endif

CONFIGURE_ARGS+=	-prefix ${PREFIX} \
		-incdir ${CYCINCDIR} -bindir ${CYCBINDIR} -libdir ${CYCLIBDIR}

.include <bsd.port.post.mk>
