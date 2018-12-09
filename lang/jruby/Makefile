# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	jruby
PORTVERSION=	9.2.4.0
DISTVERSIONPREFIX=	bin-
CATEGORIES=	lang ruby java
MASTER_SITES=	http://jruby.org.s3.amazonaws.com/downloads/${PORTVERSION}/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Implementation of Ruby Interpreter in Pure Java

LICENSE=	EPL GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash

USES=		cpe
USE_JAVA=	yes

JAVA_VERSION=	1.8+
NO_BUILD=	yes

JRUBY_HOME?=	${PREFIX}/share/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
REPLACE_LIST=	JAVA_HOME=${JAVA_HOME}
REPLACE_LIST_TEMP=	${REPLACE_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

PLIST_SUB=	PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION} \
		JRUBY_HOME=${JRUBY_HOME:S,${PREFIX}/,,}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-patch:
	@${RM} -r \
		${WRKSRC}/lib/jni/*AIX \
		${WRKSRC}/lib/jni/*Linux \
		${WRKSRC}/lib/jni/*OpenBSD \
		${WRKSRC}/lib/jni/*SunOS \
		${WRKSRC}/lib/jni/*Windows \
		${WRKSRC}/lib/jni/Darwin \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*aix \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*cygwin \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*darwin \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*gnu \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*linux \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*netbsd \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*openbsd \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*solaris \
		${WRKSRC}/lib/ruby/stdlib/ffi/platform/*windows
	@${FIND} ${WRKSRC} \( -type f -name '*.bat' -or -name '*.exe' -or -name '*.dll' \) -delete
	@${REINPLACE_CMD} -i "" ${REPLACE_LIST_TEMP} ${WRKSRC}/bin/jruby

do-install:
	${MKDIR} ${STAGEDIR}${JRUBY_HOME}/bin ${STAGEDIR}${JRUBY_HOME}/lib
	(cd ${WRKSRC}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${JRUBY_HOME}/bin/)
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${JRUBY_HOME}/lib)
.for f in jruby jirb jgem
	${RLN} ${STAGEDIR}${JRUBY_HOME}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${RLN} ${STAGEDIR}${JRUBY_HOME}/bin/rake ${STAGEDIR}${PREFIX}/bin/jrake
	${FIND} ${STAGEDIR}${JRUBY_HOME}/lib/jni/x86_64-FreeBSD -type f -name '*\.so' -exec ${STRIP_CMD} {} \;

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
