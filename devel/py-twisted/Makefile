# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	0.99.2
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

# - Defining the variable WITHOUT_TESTS at build time will remove the
#   dependency on PyUnit (which has a few large dependencies).  This will
#   allow this port to build with no runtime dependencies except Python
#   itself - often ideal for server machines running production code based
#   on Twisted.
#
# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

.if !defined(WITHOUT_TESTS)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/unittest.py:${PORTSDIR}/devel/py-unit \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
MAN1=		coil.1 im.1 manhole.1 mktap.1 t-im.1 tapconvert.1 twistd.1

post-patch:
	@ ${REINPLACE_CMD} -e 's/from pyunit import/import/g' \
	  ${WRKSRC}/admin/runtests ${WRKSRC}/twisted/test/*.py

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

post-install:
	@ ${MKDIR} ${DATADIR}/admin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/admin/accepttests \
	  ${WRKSRC}/admin/runtests ${DATADIR}/admin
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/doc/man/${manpage} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
.for docsubdir in api fun howto img legal specifications howto/listings/TwistedQuotes
	@ ${MKDIR} ${DOCSDIR}/${docsubdir}
	@ ${FIND} ${WRKSRC}/doc/${docsubdir} -type f -maxdepth 1 | \
	  ${XARGS} -J %% ${INSTALL_DATA} %% ${DOCSDIR}/${docsubdir}
.endfor
.for docfile in CREDITS ChangeLog ERRATA README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}/scripts ${EXAMPLESDIR}/static
	@ ${INSTALL_DATA} ${WRKSRC}/doc/examples/* ${EXAMPLESDIR}/scripts
	@ ${INSTALL_DATA} ${WRKSRC}/static/* ${EXAMPLESDIR}/static
.endif

.include <bsd.port.mk>
