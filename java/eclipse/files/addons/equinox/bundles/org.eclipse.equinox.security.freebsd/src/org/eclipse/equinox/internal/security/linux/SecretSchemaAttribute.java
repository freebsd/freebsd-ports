/*******************************************************************************
 * Copyright (c) 2020, 2021 Red Hat Inc.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Red Hat Inc. - initial version
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

import java.util.List;

import com.sun.jna.Structure;

public class SecretSchemaAttribute extends Structure {
	public String name;
	public int type;

	public SecretSchemaAttribute() {
	}

	public SecretSchemaAttribute(String name, int type) {
		this.name = name;
		this.type = type;
		write();
	}

	@Override
	protected List<String> getFieldOrder() {
		return List.of("name", "type"); //$NON-NLS-1$ //$NON-NLS-2$
	}
}
