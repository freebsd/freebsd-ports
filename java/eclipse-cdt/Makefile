PORTNAME=	cdt
PORTVERSION=	9.0.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	ECLIPSE/tools/${PORTNAME}/releases/9.0/sr1 \
		ECLIPSE/releases/neon/201606221000:base
PKGNAMEPREFIX=	eclipse-
DISTFILES=	${BUNDLES} \
		${BUNDLE_DEPS:S/$/:base/}

MAINTAINER=	mizhka@gmail.com
COMMENT=	C/C++ plugin for Eclipse IDE
WWW=		https://www.eclipse.org/cdt/

LICENSE=	EPL

RUN_DEPENDS=	eclipse:java/eclipse

USES=		java zip
JAVA_OS=	native

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/

BUILDDATE=	20160715
BUILDTIME=	1550

FEATURES=	org.eclipse.cdt.arduino \
		org.eclipse.cdt.autotools.source \
		org.eclipse.cdt.autotools \
		org.eclipse.cdt.build.crossgcc \
		org.eclipse.cdt.bupc \
		org.eclipse.cdt.core.lrparser.feature \
		org.eclipse.cdt.core.lrparser.sdk \
		org.eclipse.cdt.core.lrparser.source \
		org.eclipse.cdt.core.parser.upc.feature \
		org.eclipse.cdt.core.parser.upc.sdk \
		org.eclipse.cdt.core.parser.upc.source \
		org.eclipse.cdt.debug.gdbjtag \
		org.eclipse.cdt.debug.standalone.source \
		org.eclipse.cdt.debug.standalone \
		org.eclipse.cdt.debug.ui.memory.source \
		org.eclipse.cdt.debug.ui.memory \
		org.eclipse.cdt.docker.launcher.source \
		org.eclipse.cdt.docker.launcher \
		org.eclipse.cdt.examples.dsf \
		org.eclipse.cdt.gdb.source \
		org.eclipse.cdt.gdb \
		org.eclipse.cdt.gnu.build.source \
		org.eclipse.cdt.gnu.build \
		org.eclipse.cdt.gnu.debug.source \
		org.eclipse.cdt.gnu.debug \
		org.eclipse.cdt.gnu.dsf.source \
		org.eclipse.cdt.gnu.dsf \
		org.eclipse.cdt.gnu.multicorevisualizer \
		org.eclipse.cdt.launch.remote \
		org.eclipse.cdt.managedbuilder.llvm \
		org.eclipse.cdt.msw \
		org.eclipse.cdt.native.source \
		org.eclipse.cdt.native \
		org.eclipse.cdt.platform.source \
		org.eclipse.cdt.platform \
		org.eclipse.cdt.qt \
		org.eclipse.cdt.remote \
		org.eclipse.cdt.sdk \
		org.eclipse.cdt.testsrunner.feature \
		org.eclipse.cdt.testsrunner.source.feature \
		org.eclipse.cdt.util \
		org.eclipse.cdt.visualizer \
		org.eclipse.cdt.xlc.feature \
		org.eclipse.cdt.xlc.sdk \
		org.eclipse.cdt.xlc.source \
		org.eclipse.cdt
PLUGINS=	org.eclipse.cdt.arduino.core_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.arduino.ui_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.autotools.core.source_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.autotools.core_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.autotools.docs_2.0.2.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.autotools.ui.source_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.autotools.ui_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.build.crossgcc_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.build.gcc.core.source_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.build.gcc.core_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.checkers.source_3.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.checkers.ui.source_3.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.checkers.ui_3.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.checkers_3.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.core.cxx.source_3.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.core.cxx_3.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.core.source_4.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.core_4.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.ui.cxx.source_3.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.ui.cxx_3.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.ui.source_3.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.codan.ui_3.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.lrparser.source_5.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.lrparser.xlc.source_5.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.lrparser.xlc_5.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.lrparser_5.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.native.source_5.9.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.native_5.9.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.parser.upc.source_5.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.parser.upc_5.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core.source_6.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.core_6.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.application.doc_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.application.source_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.application_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.core.source_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.core_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.gdbjtag.core_9.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.gdbjtag.ui_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.gdbjtag_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.floatingpoint.source_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.floatingpoint_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.memorybrowser.source_1.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.memorybrowser_1.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.search.source_1.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.search_1.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.traditional.source_1.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.traditional_1.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.transport.source_2.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.memory.transport_2.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui.source_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.debug.ui_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.doc.isv_5.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.doc.user_5.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.docker.launcher.source_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.docker.launcher_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.gdb.multicorevisualizer.ui_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.gdb.source_5.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.gdb.ui.source_2.6.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.gdb.ui_2.6.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.gdb_5.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.source_2.7.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.ui.source_2.5.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf.ui_2.5.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.dsf_2.7.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.errorparsers.xlc.source_5.0.100.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.errorparsers.xlc_5.0.100.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.examples.dsf.pda.ui_2.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.examples.dsf.pda_2.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.examples.dsf_2.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.gdb.source_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.gdb.ui.source_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.gdb.ui_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.gdb_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.launch.remote.source_2.5.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.launch.remote_2.5.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.launch.source_9.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.launch_9.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.make.core.source_7.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.make.core_7.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.make.ui.source_7.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.make.ui_7.2.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.make.xlc.core.source_5.2.100.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.make.xlc.core_5.2.100.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.bupc.ui_1.0.3.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.core.source_8.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.core_8.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.gnu.ui.source_8.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.gnu.ui_8.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.llvm.ui_1.1.7.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.ui.source_9.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.ui_9.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.xlc.core.source_5.0.1.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.xlc.core_5.0.1.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.xlc.ui.source_6.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.xlc.ui_6.4.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.xlupc.ui.source_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.managedbuilder.xlupc.ui_1.1.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.msw.build_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.native.serial.source_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.native.serial_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.qt.core_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.qt.ui_2.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.remote.core_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.sdk_9.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.boost.source_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.boost_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.gtest.source_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.gtest_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.qttest.source_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.qttest_7.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.source_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.tap.source_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner.tap_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.testsrunner_8.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.ui.source_6.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.ui_6.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.util_5.0.100.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.visualizer.core_1.0.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt.visualizer.ui_1.3.0.${BUILDDATE}${BUILDTIME} \
		org.eclipse.cdt_9.0.0.${BUILDDATE}${BUILDTIME} \
		com.google.gson_2.2.4.v201311231704 \
		net.sourceforge.lpg.lpgjavaruntime_1.1.0.v201004271650 \
		org.eclipse.tools.templates.core_1.0.0.201607071447 \
		org.eclipse.tools.templates.freemarker_1.0.0.201607071447 \
		org.eclipse.tools.templates.ui_1.0.0.201607071447 \
		org.freemarker_2.3.22.v20160210-1233
DEPSLIST=	com.fasterxml.jackson.core.jackson-annotations_2.5.0.v201504151636.jar \
		com.fasterxml.jackson.core.jackson-core_2.5.0.v201504151636.jar \
		com.fasterxml.jackson.core.jackson-databind_2.5.0.v201504151636.jar \
		com.fasterxml.jackson.datatype.jackson-datatype-guava_2.5.0.v201504151636.jar \
		com.fasterxml.jackson.jaxrs.jackson-jaxrs-base_2.5.0.v201504171603.jar \
		com.fasterxml.jackson.jaxrs.jackson-jaxrs-json-provider_2.5.0.v201504171603.jar \
		com.google.guava_15.0.0.v201403281430.jar \
		com.kenai.jffi_1.2.7.v201505052040.jar \
		com.spotify.docker.client_3.4.0.v20160411-1914.jar \
		javassist_3.13.0.GA_v201209210905.jar \
		javax.ws.rs_2.0.1.v201504171603.jar \
		jnr.constants_0.8.6.v201505052040.jar \
		jnr.enxio_0.6.0.v201505052040.jar \
		jnr.ffi_2.0.1.v201505052040.jar \
		jnr.posix_3.0.9.v201505052040.jar \
		jnr.unixsocket_0.5.0.v201505052040.jar \
		jnr.x86asm_1.0.2.v201505052040.jar \
		org.aopalliance_1.0.0.v201105210816.jar \
		org.apache.commons.compress_1.6.0.v201310281400.jar \
		org.bouncycastle.bcpkix_1.51.0.v201505131810.jar \
		org.bouncycastle.bcprov_1.51.0.v201505131810.jar \
		org.eclipse.launchbar.core_2.0.0.201606032238.jar \
		org.eclipse.launchbar.remote.core_1.0.0.201606032238.jar \
		org.eclipse.launchbar.remote.ui_1.0.0.201606032238.jar \
		org.eclipse.launchbar.ui_2.0.0.201606032238.jar \
		org.eclipse.launchbar.ui.controls_1.0.0.201606032238.jar \
		org.eclipse.linuxtools.docker.core_2.0.0.201606101757.jar \
		org.eclipse.linuxtools.docker.editor_1.0.0.201606101757.jar \
		org.eclipse.linuxtools.docker.ui_2.0.0.201606101757.jar \
		org.eclipse.remote.console_1.1.0.201605242106.jar \
		org.eclipse.remote.core_2.1.0.201605242106.jar \
		org.eclipse.remote.doc.isv_1.0.0.201605242106.jar \
		org.eclipse.remote.jsch.core_1.0.0.201605242106.jar \
		org.eclipse.remote.jsch.ui_1.0.0.201605242106.jar \
		org.eclipse.remote.serial.core_1.0.0.201605242106.jar \
		org.eclipse.remote.serial.ui_1.0.0.201605242106.jar \
		org.eclipse.remote.telnet.core_1.0.0.201605242106.jar \
		org.eclipse.remote.telnet.ui_1.0.0.201605242106.jar \
		org.eclipse.remote.ui_2.0.0.201605242106.jar \
		org.eclipse.tm.terminal.control_4.1.0.201512010231.jar \
		org.eclipse.tm.terminal.view.core_4.0.0.201512160834.jar \
		org.glassfish.hk2.api_2.3.0.b10_v201508191500.jar \
		org.glassfish.hk2.locator_2.3.0.b10_v201508191500.jar \
		org.glassfish.hk2.osgi-resource-locator_2.3.0.b10_v201508191500.jar \
		org.glassfish.hk2.utils_2.3.0.b10_v201508191500.jar \
		org.glassfish.jersey.apache.connector_2.14.0.v201504171603.jar \
		org.glassfish.jersey.bundles.repackaged.jersey-guava_2.14.0.v201504151636.jar \
		org.glassfish.jersey.core.jersey-client_2.14.0.v201504211925.jar \
		org.glassfish.jersey.core.jersey-common_2.14.0.v201504171603.jar \
		org.glassfish.jersey.media.jersey-media-json-jackson_2.14.0.v201504171603.jar \
		org.objectweb.asm_4.0.0.v201302062210.jar \
		org.slf4j.api_1.7.2.v20121108-1250.jar

FEATURESLIST=	${FEATURES:S/$/_${PORTVERSION}.${BUILDDATE}${BUILDTIME}.jar/}
PLUGINSLIST=	${PLUGINS:S/$/.jar/}

BUNDLES=	${FEATURESLIST:S/^/features\//} \
		${PLUGINSLIST:S/^/plugins\//}

BUNDLE_DEPS=	${DEPSLIST:S/^/plugins\//}

FEATURESWRK=	${FEATURESLIST:S/^/${WRKSRC}\//}
PLUGINSWRK=	${PLUGINSLIST:S/^/${WRKSRC}\//}
DEPSWRK=	${DEPSLIST:S/^/${WRKSRC}\//}

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

FEATURESINST=	${FEATURESLIST:S/^/${WRKSRC}\//}
PLUGINSINST=	${PLUGINSLIST:S/^/${WRKSRC}\//}

post-patch:
	@${MKDIR} ${WRKSRC}/features
	@${MV} ${FEATURESWRK} ${WRKSRC}/features/
	@${MKDIR} ${WRKSRC}/plugins
	@${MV} ${PLUGINSWRK} ${WRKSRC}/plugins/
	@${MV} ${DEPSWRK} ${WRKSRC}/plugins/

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})

.include <bsd.port.mk>
