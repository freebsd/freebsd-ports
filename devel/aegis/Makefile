# New ports collection makefile for:	aegis
# Date created:		2003-06-23
# Whom: 		vance@aurema.com
#
# $FreeBSD$
#

PORTNAME=	aegis
PORTVERSION=	4.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vance@aurema.com
COMMENT=	Transaction-based software configuration management system

BROKEN=		Changes ownership of installed locale files

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-nlsdir=${LOCALBASE}/share/locale
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	ae-sccs-put.1 ae_c.1 ae_p.1 aeannotate.1 aeb.1 aebuffy.1 \
	aeca.1 aecd.1 aechown.1 aeclean.1 aeclone.1 aecomp.1 \
	aecomplete.1 aecp.1 aecpu.1 aed.1 aedb.1 aedbu.1 aede.1 \
	aedeu.1 aedist.1 aedn.1 aeedit.1 aefind.1 aefp.1 aeget.1 \
	aegis.1 aegis.cgi.1 aeib.1 aeibu.1 aeifail.1 aeimport.1 \
	aeintegratq.1 aeipass.1 ael.1 aelic.1 aels.1 aemeasure.1 \
	aemt.1 aemtu.1 aemv.1 aemvu.1 aena.1 aenbr.1 aenbru.1 aenc.1 \
	aencu.1 aend.1 aenf.1 aenfu.1 aeni.1 aenpa.1 aenpr.1 aenrls.1 \
	aenrv.1 aent.1 aentu.1 aepa.1 aepatch.1 aer.1 aera.1 aerb.1 \
	aerbu.1 aerd.1 aerect.1 aerfail.1 aeri.1 aerm.1 aermpr.1 \
	aermu.1 aerpa.1 aerpass.1 aerpu.1 aerrv.1 aesub.1 aet.1 aetar.1 \
	aev.1 aexml.1 tkaeca.1 tkaegis.1 tkaenc.1 tkaepa.1 tkaer.1
MAN5=	aecattr.5 aecstate.5 aedir.5 aefstate.5 aegis.5 aegstate.5 \
	aelock.5 aemetrics.5 aepattr.5 aepconf.5 aepstate.5 aer.5  \
	aerptidx.5 aesub.5 aetest.5 aeuconf.5 aeustate.5

DOCS=		lib/en/*.txt lib/en/*.ps*
DOCS_DE=	lib/de/*.txt lib/de/*.ps*

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}/de
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${DOCS} ${DOCSDIR} && \
		${INSTALL_DATA} ${DOCS_DE} ${DOCSDIR}/de
.endif

.include <bsd.port.post.mk>
