# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	0.19.0
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/unittest.py:${PORTSDIR}/devel/py-unit \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
CPIO=		cpio --quiet -pdum -R
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
MAN1=		coil.1 im.1 manhole.1 mktap.1 t-im.1 twistd.1

post-patch:
	@ ${PERL} -pi -e 's/from pyunit import/import/g' \
	  ${WRKSRC}/admin/runtests ${WRKSRC}/twisted/test/*.py

post-install:
	@ ${MKDIR} ${DATADIR}/admin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/admin/accepttests \
	  ${WRKSRC}/admin/runtests ${DATADIR}/admin
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/doc/man/${manpage} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
.for docsubdir in api howto
	@ ${MKDIR} ${DOCSDIR}/${docsubdir}
	@ cd ${WRKSRC}/doc/${docsubdir} && find * \! -name .\* \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/${docsubdir}
.endfor
.for docsubdir in img legal specifications
	@ ${MKDIR} ${DOCSDIR}/${docsubdir}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${docsubdir}/* ${DOCSDIR}/${docsubdir}
.endfor
.for docfile in CREDITS ChangeLog ERRATA README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}/scripts ${EXAMPLESDIR}/static
	@ ${INSTALL_DATA} ${WRKSRC}/doc/examples/* ${EXAMPLESDIR}/scripts
	@ ${INSTALL_DATA} ${WRKSRC}/static/* ${EXAMPLESDIR}/static
.endif

.include <bsd.port.mk>
