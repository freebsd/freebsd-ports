# New ports collection makefile for:	py-twisted
# Date created:		16 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twisted
PORTVERSION=	1.1.0
CATEGORIES=	devel net python
MASTER_SITES=	http://twisted.sourceforge.net/ \
		http://twistedmatrix.com/downloads/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Twisted-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	An event-based Python framework for internet applications

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the funcitoning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome
#   separately if desired.

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAN1=		ckeygen.1 conch.1 im.1 lore.1 mailmail.1 manhole.1 \
		mktap.1 t-im.1 tap2deb.1 tap2rpm.1 tapconvert.1 \
		tkconch.1 tkmktap.1 trial.1 twistd.1 websetroot.1

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
	@ ${MKDIR} ${DOCSDIR}/man
.for docfile in CREDITS ChangeLog README
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for htmlman in ${MAN1:S/.1/-man.html/}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/man/${htmlman} ${DOCSDIR}/man
.endfor
	@ cd ${WRKSRC}/doc && \
	  ${FIND} * -type d -maxdepth 0 \! -name examples \! -name man | \
	  ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
	@ ${MKDIR} ${EXAMPLESDIR}/scripts ${EXAMPLESDIR}/static
	@ ${CP} -R ${WRKSRC}/doc/examples/* ${EXAMPLESDIR}/scripts
	@ ${CP} -R ${WRKSRC}/static/* ${EXAMPLESDIR}/static
.endif

.include <bsd.port.mk>
